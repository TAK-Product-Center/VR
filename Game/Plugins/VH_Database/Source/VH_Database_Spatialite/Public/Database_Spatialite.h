#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Misc/Variant.h"

// Generated Includes
#include "Database_Spatialite.generated.h"

/*
Example Usage:

	// --- Add and object to database
	FString xml = TEXT("hello world");

	FBufferArchive toBinary;
	toBinary << xml;
	TArray<uint8> data = (TArray<uint8>&)toBinary;

	TArray<double> northWestBB;
	northWestBB.Add(0);
	northWestBB.Add(1);

	TArray<double> southEastBB;
	southEastBB.Add(2);
	southEastBB.Add(3);

	if (sqlite3_stmt* statement = EntityDB->PrepareStatement(TEXT("insert into entities (northWestBB, southEastBB, data) values (?, ?, ?)")))
	{
		EntityDB->BindPoint(statement, northWestBB, 1);
		EntityDB->BindPoint(statement, southEastBB, 2);
		EntityDB->BindBlob(statement, data, 3);

		EntityDB->SyncQuery(statement);
	}

	// --- Retrieve objects from database
	SpatialiteResults results;
	EntityDB->SyncQuery(TEXT("select * from entities"), results);

	for (const SpatialiteResult& result : results)
	{
		TArray<double> northWestBB = UDatabase_Spatialite::GetPoint(TEXT("northWestBB"), result);

		TArray<double> southEastBB = UDatabase_Spatialite::GetPoint(TEXT("southEastBB"), result);

		TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

		FMemoryReader fromBinary = FMemoryReader(blob);
		fromBinary.Seek(0);

		FString xmlResult;
		fromBinary << xmlResult;

		UE_LOG(LogTemp, Warning, TEXT("-- nw: %s | se: %s | xml: %s"), *nw.ToString(), *se.ToString(), *xmlResult);
	}
*/

struct sqlite3;
struct sqlite3_stmt;

typedef TMap<FString, FVariant> SpatialiteResult;
typedef TArray<SpatialiteResult> SpatialiteResults;

// work-around for dynamic delegates
USTRUCT(BlueprintType)
struct FSpatialiteResult_BP
{
    GENERATED_BODY()

    SpatialiteResult Result;

	FSpatialiteResult_BP()
	{

	}

	FSpatialiteResult_BP(const SpatialiteResult& result)
	{
		Result = result;
	}

	bool NetSerialize(FArchive& ar, class UPackageMap* map, bool& bOutSuccess)
	{
		if (ar.IsSaving())
		{
			int32 num = Result.Num();
			ar << num;

			for (const TPair<FString, FVariant>& entry : Result)
			{
				FString key = entry.Key;
				ar << key;

				FVariant value = entry.Value;
				ar << value;
			}
		}
		else
		{
			int32 num;
			ar << num;

			for (int32 i = 0; i < num; i++)
			{
				FString key;
				ar << key;

				FVariant value;
				ar << value;

				Result.Add(key, value);
			}
		}

		bOutSuccess = true;

		return true;
	}
};

template<>
struct TStructOpsTypeTraits<FSpatialiteResult_BP> : public TStructOpsTypeTraitsBase2<FSpatialiteResult_BP>
{
	enum
	{
		WithNetSerializer = true
	};
};

// work-around for dynamic delegates
USTRUCT(BlueprintType)
struct FSpatialiteResults_BP
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    TArray<FSpatialiteResult_BP> Results;

    FSpatialiteResults_BP()
    {

    }

    FSpatialiteResults_BP(const SpatialiteResults& results)
    {
        for (const SpatialiteResult& result : results)
        {
            FSpatialiteResult_BP resultBP;
            resultBP.Result = result;

            Results.Add(resultBP);
        }
    }
};

UCLASS(Blueprintable, BlueprintType)
class VH_DATABASE_SPATIALITE_API UDatabase_Spatialite : public UObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

protected:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDBEvent, const FSpatialiteResults_BP&, results);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	FString PrimaryTableName;

	TMap<FString, FString> PrimaryTableFields;

	TArray<FString> PrimaryTableAdditionalInitQueries;

private:
	bool bInitialized;

	sqlite3* DatabaseHandle;

	FString FullPathToDatabase;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDatabase_Spatialite();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
    UFUNCTION(BlueprintPure)
    static bool GetBool(const FString& columnName, const FSpatialiteResult_BP& result_BP);
	static bool GetBool(const FString& columnName, const SpatialiteResult& result);

	UFUNCTION(BlueprintPure)
	static int32 GetInteger(const FString& columnName, const FSpatialiteResult_BP& result_BP);
    static int32 GetInteger(const FString& columnName, const SpatialiteResult& result);

	UFUNCTION(BlueprintPure)
	static int64 GetInteger64(const FString& columnName, const FSpatialiteResult_BP& result_BP);
	static int64 GetInteger64(const FString& columnName, const SpatialiteResult& result);

	UFUNCTION(BlueprintPure)
	static double GetDouble(const FString& columnName, const FSpatialiteResult_BP& result_BP);
    static double GetDouble(const FString& columnName, const SpatialiteResult& result);

	UFUNCTION(BlueprintPure)
	static FString GetString(const FString& columnName, const FSpatialiteResult_BP& result_BP);
    static FString GetString(const FString& columnName, const SpatialiteResult& result);

	UFUNCTION(BlueprintPure)
	static TArray<uint8> GetBlob(const FString& columnName, const FSpatialiteResult_BP& result_BP);
    static TArray<uint8> GetBlob(const FString& columnName, const SpatialiteResult& result);

	UFUNCTION(BlueprintPure)
	static TArray<double> GetPoint(const FString& columnName, const FSpatialiteResult_BP& result_BP);
    static TArray<double> GetPoint(const FString& columnName, const SpatialiteResult& result);

	UFUNCTION(BlueprintCallable)
	static void SetString(const FString& columnName, UPARAM(ref) FSpatialiteResult_BP& result_BP, const FString& value);
	static void SetString(const FString& columnName, SpatialiteResult& result, const FString& value);

	static FString ToString(const SpatialiteResult& result);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
    virtual void BeginDestroy() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
    /*
	* \brief Opens or creates database
	* \param fullPathToDatabase Full path to database file including file extension
	* \param bAllowCreate Create database if it does not exist
	* \return True on success
	*/
    bool OpenDatabase(const FString& fullPathToDatabase, bool bAllowCreate);

    /*
	* \brief Executes a synchronous query
	* \param query String query to execute
	* \return True on success
	*/
    bool SyncQuery(const FString& query) const;

    /*
	* \brief Executes a synchronous query and returns results
	* \param query String query to execute
	* \param results Reference to results to populate
	* \return True on success
	*/
    bool SyncQuery(const FString& query, SpatialiteResults& results) const;

    /*
	* \brief Executes a synchronous query from a statement
	* \param statement Statement to use for query
	* \return True on success
	*/
    bool SyncQuery(sqlite3_stmt* statement) const;

    /*
	* \brief Executes a synchronous query from a statement and returns results
	* \param statement Statement to use for query
	* \param results Reference to results to populate
	* \return True on success
	*/
    bool SyncQuery(sqlite3_stmt* statement, SpatialiteResults& results) const;

    /*
	* \brief Prepares a statement based on string query
	* \param query String query to execute
	* \return Pointer to sqlite3_stmt on success
	*/
    sqlite3_stmt* PrepareStatement(const FString& query) const;

    /*
	* \brief Binds blob to statement
	* \param statement Statement to use for query
	* \param blob Byte array to bind
	* \param variableIndex index of variable in query (starts at 1)
	* \return True on success
	*/
    bool BindBlob(sqlite3_stmt* statement, const TArray<uint8>& blob, int32 variableIndex) const;

    /*
	* \brief Binds point to statement
	* \param statement Statement to use for query
	* \param doubleArray Double values of point; must be 2, 3, or 4 elements
	* \param variableIndex index of variable in query (starts at 1)
	* \return True on success
	*/
    bool BindPoint(sqlite3_stmt* statement, const TArray<double>& doubleArray, int32 variableIndex) const;

	void Disconnect();

	bool SerializeToByteArray(const FString& fullPathToDB, const FString& fullPathToTemp, TArray<uint8>& data);

	bool IsDatabaseReady() const;

	/*
	* \brief Creates primary table
	* \param tableName Name of table
	* \param tableFields Table fields; ex: PrimaryTableFields.Add(TEXT("entityUID"), TEXT("string not null"));
	* \param queries Additional queries to run after creating table
	* \param bReplace If true, drops table with tableName before table creation
	*/
	void CreatePrimaryTable(const FString& tableName, const TMap<FString, FString>& tableFields, const TArray<FString> queries, bool bReplace);

	FString GetPrimaryTableName() const;

	FString GetFullPathToDatabase() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	UFUNCTION()
	void Initialize();

	/* \brief Called after Initialize
	*  \return True on successful initialization
	*/
	virtual bool PostInitialize();

	void Cleanup();

	virtual void PostCleanup();

    void AddRowToResults(sqlite3_stmt* statement, SpatialiteResults& results) const;

    FVariant GetVariantForRow(sqlite3_stmt* statement, int32 columnIndex) const;
};
