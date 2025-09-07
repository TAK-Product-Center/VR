#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Misc/Variant.h"
#include "TimerManager.h"

// Generated Includes
#include "Database_MySQL.generated.h"

/*
Example Usage:

	// --- Add and object to database
	FString xml = TEXT("hello world");

	FBufferArchive toBinary;
	toBinary << xml;
	TArray<uint8> data = (TArray<uint8>&)toBinary;

	if (sqlite3_stmt* statement = EntityDB->PrepareStatement(TEXT("insert into entities (data) values (?)")))
	{
		EntityDB->BindBlob(statement, data, 1);

		EntityDB->SyncQuery(statement);
	}

	// --- Retrieve objects from database
	MySQLResults results;
	EntityDB->SyncQuery(TEXT("select * from entities"), results);

	for (const MySQLResult& result : results)
	{
		TArray<uint8> blobData = UVH_MySQL::GetBlob(TEXT("data"), result);

		FMemoryReader fromBinary = FMemoryReader(blob);
		fromBinary.Seek(0);

		FString xmlResult;
		fromBinary << xmlResult;

		UE_LOG(LogTemp, Warning, TEXT("-- xml: %s"), *xmlResult);
	}
*/

namespace sql
{
	class Connection;
	class Statement;
	class PreparedStatement;
	class ResultSet;
	class ResultSetMetaData;
}

typedef TMap<FString, FVariant> MySQLResult;
typedef TArray<MySQLResult> MySQLResults;

FORCEINLINE FArchive& operator<<(FArchive& ar, MySQLResult& result)
{
	if (ar.IsLoading())
	{
		int32 numEntries;
		ar << numEntries;

		for (int32 i = 0; i < numEntries; i++)
		{
			FString key;
			ar << key;

			FVariant value;
			ar << value;

			result.Add(key, value);
		}
	}
	else
	{
		int32 numEntries = result.Num();
		ar << numEntries;

		for (const TPair<FString, FVariant>& entry : result)
		{
			FString key = entry.Key;
			ar << key;

			FVariant value = entry.Value;
			ar << value;
		}
	}

	return ar;
}

// work-around for dynamic delegates
USTRUCT(BlueprintType)
struct FMySQLResult_BP
{
    GENERATED_BODY()

    MySQLResult Result;

	FMySQLResult_BP()
	{

	}

	FMySQLResult_BP(const MySQLResult& result)
	{
		Result = result;
	}
};

// work-around for dynamic delegates
USTRUCT(BlueprintType)
struct FMySQLResults_BP
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    TArray<FMySQLResult_BP> Results;

    FMySQLResults_BP()
    {

    }

    FMySQLResults_BP(const MySQLResults& results)
    {
        for (const MySQLResult& result : results)
        {
            FMySQLResult_BP resultBP;
            resultBP.Result = result;

            Results.Add(resultBP);
        }
    }
};

class UReplication_DataChannel;

UCLASS(Blueprintable, BlueprintType)
class VH_DATABASE_MYSQL_API UDatabase_MySQL : public UObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_MULTICAST_DELEGATE_OneParam(FAsyncCallback, const MySQLResults&);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	FString PrimaryTableName;

	TMap<FString, FString> PrimaryTableFields;

	TArray<FString> PrimaryTableAdditionalInitQueries;

private:
	bool bInitialized;

	sql::Connection* Connection;

	FString ReplicationID;

	/* maps UID to callback */
	TMap<FString, FAsyncCallback> ReplicatedQueryCallbacks;

	TArray<TPair<FString, FAsyncCallback>> PendingReplicatedQueries;

	FTimerHandle PendingReplicatedQueriesHandle;
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDatabase_MySQL();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
    UFUNCTION(BlueprintPure)
    static bool GetBool(const FString& columnName, const FMySQLResult_BP& result_BP);
	static bool GetBool(const FString& columnName, const MySQLResult& result);

	UFUNCTION(BlueprintPure)
	static int32 GetInteger(const FString& columnName, const FMySQLResult_BP& result_BP);
    static int32 GetInteger(const FString& columnName, const MySQLResult& result);

	UFUNCTION(BlueprintPure)
	static int64 GetInteger64(const FString& columnName, const FMySQLResult_BP& result_BP);
	static int64 GetInteger64(const FString& columnName, const MySQLResult& result);

	UFUNCTION(BlueprintPure)
	static double GetDouble(const FString& columnName, const FMySQLResult_BP& result_BP);
    static double GetDouble(const FString& columnName, const MySQLResult& result);

	UFUNCTION(BlueprintPure)
	static FString GetString(const FString& columnName, const FMySQLResult_BP& result_BP);
    static FString GetString(const FString& columnName, const MySQLResult& result);

	UFUNCTION(BlueprintPure)
	static TArray<uint8> GetBlob(const FString& columnName, const FMySQLResult_BP& result_BP);
    static TArray<uint8> GetBlob(const FString& columnName, const MySQLResult& result);

	UFUNCTION(BlueprintCallable)
	static void SetString(const FString& columnName, UPARAM(ref) FMySQLResult_BP& result_BP, const FString& value);
	static void SetString(const FString& columnName, MySQLResult& result, const FString& value);


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
	* \brief Sets replicationID for sending queries to server
	* \param replicationID ID to use for replication
	*/
	void SetReplicationID(const FString& replicationID);

    /*
	* \brief Opens or creates database
	* \param server Host to connect
	* \param database Name of database to use
	* \param username Username to use for credentials when connecting
	* \param password Password to use for credentials when connecting
	* \return True on success
	*/
    bool OpenDatabase(const FString& server, const FString& database, const FString& username, const FString& password);

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
    bool SyncQuery(const FString& query, MySQLResults& results) const;

    /*
	* \brief Executes a synchronous query from a statement
	* \param preparedStatement Prepared statement to use for query
	* \return True on success
	*/
    bool SyncQuery(sql::PreparedStatement* preparedStatement) const;

    /*
	* \brief Executes a synchronous query from a statement and returns results
	* \param preparedStatement Prepared statement to use for query
	* \param results Reference to results to populate
	* \return True on success
	*/
    bool SyncQuery(sql::PreparedStatement* preparedStatement, MySQLResults& results) const;

	/*
	* \brief Executes an asynchronous query
	* \param query String query to execute
	*/
	void AsyncQuery(const FString& query);

	/*
	* \brief Executes an asynchronous query and returns results
	* \param query String query to execute
	* \param callback Delegate to broadcast (in game thread) when query returns
	*/
	void AsyncQuery(const FString& query, FAsyncCallback callback);

	/*
	* \brief Executes an asynchronous query from a statement
	* \param preparedStatement Prepared statement to use for query
	*/
	void AsyncQuery(sql::PreparedStatement* preparedStatement);

	/*
	* \brief Executes a synchronous query from a statement and returns results
	* \param preparedStatement Prepared statement to use for query
	* \param callback Delegate to broadcast (in game thread) when query returns
	*/
	void AsyncQuery(sql::PreparedStatement* preparedStatement, FAsyncCallback callback);

    /*
	* \brief Prepares a statement based on string query
	* \param query String query to execute
	* \return Pointer to sqlite3_stmt on success
	*/
	sql::PreparedStatement* PrepareStatement(const FString& query) const;

    /*
	* \brief Binds blob to statement
	* \param preparedStatement Prepared statement to use for query
	* \param blob Byte array to bind
	* \param variableIndex index of variable in query (starts at 1)
	*/
    void BindBlob(sql::PreparedStatement* preparedStatement, const TArray<uint8>& blob, int32 variableIndex) const;

	void Disconnect();

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


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool Initialize();

	/* \brief Called after Initialize
	*  \return True on successful initialization
	*/
	virtual bool PostInitialize();

	void Cleanup();

	virtual void PostCleanup();

	void AddRowToResults(sql::ResultSet* resultSet, sql::ResultSetMetaData* resultSetMetaData, MySQLResults& results) const;

    FVariant GetVariantForColumn(sql::ResultSet* resultSet, sql::ResultSetMetaData* resultSetMetaData, unsigned int columnIndex) const;

	void ExecutePendingReplicatedQueries();

	bool IsReadyToReplicateQueries() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleDataReceived(const TArray<uint8>& data, UReplication_DataChannel* channel);
};
