#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "XmlFile.h"
#include "XmlNode.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Module Includes
#include "VH_COTStatics.h"

// Generated Includes
#include "VH_COTEvent.generated.h"

UCLASS(BlueprintType)
class VH_COT_API UVH_COTEvent : public UObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	static TMap<FString, FString> XmlKeywords;

	TSharedPtr<FXmlFile> XmlFile;

	// passed through from CommoListener::cotMessageReceived
    FString CommoInterfaceEndpointID;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVH_COTEvent();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:	
	/// @brief Returns true and populates value with attribute's value if it exists
	///	       Ex: <event><point lat=xyz/></event> is pathToAttribute = TEXT("event\tpoint\tlat")
	template <class T = FString>
	bool TryGetAttribute(const FString& pathToAttribute, T& value) const
	{
		if (FXmlNode* node = XmlFile->GetRootNode())
		{
			FString path = pathToAttribute;
			if (FString* pathPtr = XmlKeywords.Find(pathToAttribute))
			{
				path = *pathPtr;
			}

			TArray<FString> parsed;
			path.ParseIntoArray(parsed, TEXT("\t"));

			for (int32 i = 0; i < parsed.Num(); i++)
			{
				if (i < parsed.Num() - 1)
				{
					node = node->FindChildNode(parsed[i]);
					if (node == nullptr)
					{
						//FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UVH_COTEvent::TryGetAttribute | could not path to node | %s | returning false"), *pathToAttribute);
						return false;
					}
				}
				else
				{
					FVariant valueVariant = value;
					
					FString valueString = node->GetAttribute(parsed[i]);

					UVH_COTStatics::PopulateVariant(valueVariant, valueString);
					
					value = valueVariant.GetValue<T>();
                
					return true;
				}
			}
		}

		FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- UVH_COTEvent::TryGetAttribute | error | %s | returning false"), *pathToAttribute);
		return false;
	}

	template <> 
	bool TryGetAttribute<FDateTime>(const FString& pathToAttribute, FDateTime& value) const
	{
		FString valueString;
		if (TryGetAttribute(pathToAttribute, valueString))
		{
			value = UVH_COTStatics::GetDateTime(valueString);

			return true;
		}

		return false;
	}

	template <> 
	bool TryGetAttribute<FColor>(const FString& pathToAttribute, FColor& value) const
	{
		FString valueString;
		if (TryGetAttribute(pathToAttribute, valueString))
		{
			value = UVH_COTStatics::DecimalAttributeToColor(valueString);

			return true;
		}

		value = FLinearColor(1.f, 0.161886f, 0.032147f, 1).ToFColor(true);  // default to orange
		return false;
	}

	/// @brief Returns attribute's value if it exists; otherwise empty string
	///	       Ex: <event><point lat=xyz/></event> is pathToAttribute = TEXT("event\tpoint\tlat")
	template <class T = FString>
	T GetAttribute(const FString& pathToAttribute) const
	{
		T value;
		if (TryGetAttribute<T>(pathToAttribute, value))
		{
			return value;
		}

		return value;
	}

	/// @brief Updates (or adds) attribute with given value
	///	       Ex: <event><point lat=xyz/></event> is pathToAttribute = TEXT("event\tpoint\tlat")
	template <class T = FString>
	void SetAttribute(const FString& pathToAttribute, const T& value)
	{
		if (FXmlNode* node = XmlFile->GetRootNode())
		{
			FString path = pathToAttribute;
			if (FString* pathPtr = XmlKeywords.Find(pathToAttribute))
			{
				path = *pathPtr;
			}

			TArray<FString> parsed;
			path.ParseIntoArray(parsed, TEXT("\t"));

			for (int32 i = 0; i < parsed.Num(); i++)
			{
				if (i < parsed.Num() - 1)
				{
					FXmlNode* child = node->FindChildNode(parsed[i]);
					if (child == nullptr)
					{
						node->AppendChildNode(parsed[i]);

						node = node->FindChildNode(parsed[i]);
					}
					else
					{
						node = child;
					}
				}
				else
				{
					node->SetAttribute(parsed[i], UVH_COTStatics::VariantToString(FVariant(value)));
				}
			}
		}
	}

	template <> 
	void SetAttribute(const FString& pathToAttribute, const FDateTime& value)
	{
		FString valueString = UVH_COTStatics::GetISOTime(value);

		SetAttribute(pathToAttribute, valueString);
	}

	template <> 
	void SetAttribute(const FString& pathToAttribute, const FColor& value)
	{
		FString valueString = UVH_COTStatics::ColorToDecimalAttribute(value);

		SetAttribute(pathToAttribute, valueString);
	}

	/// @brief Returns attribute's value if it exists; otherwise empty string
	///	       Ex: <event><point lat=xyz/></event> is pathToAttribute = TEXT("event\tpoint\tlat")
	UFUNCTION(BlueprintPure)
	FString GetAttributeAsString(const FString& pathToAttribute) const;

	/// @brief Returns attribute's value if it exists; otherwise empty FDateTime
	///	       Ex: <event><point lat=xyz/></event> is pathToAttribute = TEXT("event\tpoint\tlat")
	UFUNCTION(BlueprintPure)
	FDateTime GetAttributeAsDateTime(const FString& pathToAttribute) const;

	UFUNCTION(BlueprintPure)
	FString GetNodeContent(const FString& pathToNode) const;

	/// @brief Updates (or adds) attribute with given value
	///	       Ex: <event><point lat=xyz/></event> is pathToAttribute = TEXT("event\tpoint\tlat")
	UFUNCTION(BlueprintCallable)
	void SetAttributeAsString(const FString& pathToAttribute, const FString& value);

	UFUNCTION(BlueprintCallable)
	void AddNode(const FString& pathToNode, bool bReplace = false, const FString& content = TEXT(""));

	UFUNCTION(BlueprintPure)
	FGeodeticCoord3D GetPoint() const;

	UFUNCTION(BlueprintCallable)
	void SetPoint(const FGeodeticCoord3D& coordinate);

	UFUNCTION(BlueprintCallable)
	void PopulateTime(const FTimespan& timeSpan);

	UFUNCTION(BlueprintPure)
	bool HasNode(const FString& pathToNode) const;

	UFUNCTION(BlueprintCallable)
	void RemoveNodes(const FString& pathToNode);

	void AddNode(const FString& pathToNode, const TArray<FXmlAttribute>& attributes = TArray<FXmlAttribute>(), bool bReplace = false, const FString& content = TEXT(""));

	TArray<FXmlNode*> GetNodes(const FString& pathToNode) const;

	bool PopulateFromXML(const FString& xmlString);

	bool PopulateFromXML(FXmlNode* eventNode);

	UFUNCTION(BlueprintPure)
	FString ToXML() const;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void Initialize();
};