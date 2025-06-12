// Required Includes
#include "VH_COTEvent.h"
#include "VH_COT.h"

// Module Includes
#include "VH_COTManager.h"
#include "VH_COTStatics.h"

TMap<FString, FString> MakeXmlKeywords()
{
    TMap<FString, FString> xmlKeywords;
    xmlKeywords.Add(TEXT("callsign"), TEXT("detail\tcontact\tcallsign"));
    xmlKeywords.Add(TEXT("endpoint"), TEXT("detail\tcontact\tendpoint"));
    xmlKeywords.Add(TEXT("groupName"), TEXT("detail\t__group\tname"));
    xmlKeywords.Add(TEXT("groupRole"), TEXT("detail\t__group\trole"));
    xmlKeywords.Add(TEXT("archive"), TEXT("detail\tarchive"));
    xmlKeywords.Add(TEXT("latitude"), TEXT("point\tlat"));
    xmlKeywords.Add(TEXT("longitude"), TEXT("point\tlon"));
    xmlKeywords.Add(TEXT("hae"), TEXT("point\thae"));
    xmlKeywords.Add(TEXT("link"), TEXT("detail\tlink"));
	xmlKeywords.Add(TEXT("fillColor"), TEXT("detail\tfillColor\tvalue"));
	xmlKeywords.Add(TEXT("strokeColor"), TEXT("detail\tstrokeColor\tvalue"));

    return xmlKeywords;
}

TMap<FString, FString> UVH_COTEvent::XmlKeywords = MakeXmlKeywords();

// ---------------------------------
// --- Constructors
// ---------------------------------

UVH_COTEvent::UVH_COTEvent()
{
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        Initialize();
    }
}

// ---------------------------------
// --- API
// ---------------------------------

FString UVH_COTEvent::GetAttributeAsString(const FString& pathToAttribute) const
{
	// fix tabs from blueprint
	FString path = pathToAttribute.Replace(TEXT("\\t"), TEXT("\t"));

    FString value;
    if (TryGetAttribute(path, value))
    {
        return value;
    }

    return TEXT("");
}

FDateTime UVH_COTEvent::GetAttributeAsDateTime(const FString& pathToAttribute) const
{
	// fix tabs from blueprint
	FString path = pathToAttribute.Replace(TEXT("\\t"), TEXT("\t"));

    FDateTime value;
    if (TryGetAttribute<FDateTime>(path, value))
    {
        return value;
    }

    return FDateTime();
}

FString UVH_COTEvent::GetNodeContent(const FString& pathToNode) const
{
	// fix tabs from blueprint
	FString pathReplaced = pathToNode.Replace(TEXT("\\t"), TEXT("\t"));

    if (FXmlNode* node = XmlFile->GetRootNode())
	{
		FString path = pathReplaced;
		if (FString* pathPtr = XmlKeywords.Find(pathReplaced))
		{
			path = *pathPtr;
		}

		TArray<FString> parsed;
		path.ParseIntoArray(parsed, TEXT("\t"));

		for (int32 i = 0; i < parsed.Num(); i++)
		{
			if (i < parsed.Num() - 1)
			{
				if (FXmlNode* child = node->FindChildNode(parsed[i]))
				{
					node = child;
				}
                else
                {
                    return TEXT("");
                }
			}
			else
			{
				if (FXmlNode* child = node->FindChildNode(parsed[i]))
				{
					return child->GetContent();
				}
			}
		}
	}

    return TEXT("");
}

void UVH_COTEvent::SetAttributeAsString(const FString& pathToAttribute, const FString& value)
{
	// fix tabs from blueprint
	FString path = pathToAttribute.Replace(TEXT("\\t"), TEXT("\t"));

    SetAttribute(path, value);
}

void UVH_COTEvent::AddNode(const FString& pathToNode, bool bReplace, const FString& content)
{
	// fix tabs from blueprint
	FString path = pathToNode.Replace(TEXT("\\t"), TEXT("\t"));

    AddNode(path, TArray<FXmlAttribute>(), bReplace, content);
}

FGeodeticCoord3D UVH_COTEvent::GetPoint() const
{
    FGeodeticCoord3D coordinate;

    coordinate.Longitude = GetAttribute<double>(TEXT("longitude"));
    coordinate.Latitude = GetAttribute<double>(TEXT("latitude"));
    coordinate.Altitude = GetAttribute<double>(TEXT("hae"));

    return coordinate;
}

void UVH_COTEvent::SetPoint(const FGeodeticCoord3D& coordinate)
{ 
    SetAttribute<double>(TEXT("latitude"), coordinate.Latitude);
	SetAttribute<double>(TEXT("longitude"), coordinate.Longitude);
	SetAttribute<double>(TEXT("hae"), coordinate.Altitude);
	SetAttribute<double>(TEXT("point\tce"), 9999999);
	SetAttribute<double>(TEXT("point\tle"), 9999999);
}

void UVH_COTEvent::PopulateTime(const FTimespan& activeTime)
{
    SetAttribute<FDateTime>(TEXT("time"), FDateTime::UtcNow());
    SetAttribute<FDateTime>(TEXT("start"), FDateTime::UtcNow());
    SetAttribute<FDateTime>(TEXT("stale"), FDateTime::UtcNow() + activeTime);
}

bool UVH_COTEvent::HasNode(const FString& pathToNode) const
{
	// fix tabs from blueprint
	FString pathReplaced = pathToNode.Replace(TEXT("\\t"), TEXT("\t"));

	if (FXmlNode* node = XmlFile->GetRootNode())
	{
		FString path = pathReplaced;
		if (FString* pathPtr = XmlKeywords.Find(pathReplaced))
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
				if (child != nullptr)
				{
					node = child;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (FXmlNode* child = node->FindChildNode(parsed[i]))
				{
					return true;
				}
			}
		}
	}

	return false;
}

void UVH_COTEvent::RemoveNodes(const FString & pathToNode)
{
	// fix tabs from blueprint
	FString pathReplaced = pathToNode.Replace(TEXT("\\t"), TEXT("\t"));

	if (FXmlNode* node = XmlFile->GetRootNode())
	{
		FString path = pathReplaced;
		if (FString* pathPtr = XmlKeywords.Find(pathReplaced))
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
				if (child != nullptr)
				{
					node = child;
				}
				else
				{
					return;
				}
			}
			else
			{
				node->RemoveChildNodes(parsed[i]);
			}
		}
	}
}

void UVH_COTEvent::AddNode(const FString& pathToNode, const TArray<FXmlAttribute>& attributes, bool bReplace, const FString& content)
{
	if (FXmlNode* node = XmlFile->GetRootNode())
	{
		FString path = pathToNode;
		if (FString* pathPtr = XmlKeywords.Find(pathToNode))
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
                if (bReplace)
                {
				    if (FXmlNode* child = node->FindChildNode(parsed[i]))
				    {
					    child->SetContent(content);
                        child->SetAttributes(attributes);

                        return;
				    }
                }

				node->AppendChildNode(parsed[i], content, attributes);
			}
		}
	}
}

TArray<FXmlNode*> UVH_COTEvent::GetNodes(const FString& pathToNode) const
{
    TArray<FXmlNode*> toReturn;

    if (FXmlNode* node = XmlFile->GetRootNode())
    {
        FString path = pathToNode;
		if (FString* pathPtr = XmlKeywords.Find(pathToNode))
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
                if (child != nullptr)
                {
                    node = child;
                }
				else
				{
					return TArray<FXmlNode*>();
				}
            }
            else
            {
                const TArray<FXmlNode*> children = node->GetChildrenNodes();
                for (FXmlNode* child : children)
                {
                    if (child->GetTag().Equals(parsed[i]))
                    {
                        toReturn.Add(child);
                    }
                }
            }
        }
    }

    return toReturn;
}

bool UVH_COTEvent::PopulateFromXML(const FString& xmlString)
{
    XmlFile->LoadFile(xmlString, EConstructMethod::ConstructFromBuffer);
    if (!XmlFile->IsValid())
    {
        UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTEvent::PopulateFromXML | invalid xml file | %s"), *xmlString);

        return false;
    }

    return true;
}

bool UVH_COTEvent::PopulateFromXML(FXmlNode* eventNode)
{
    if (eventNode != nullptr)
    {
		FString xml;
		FXmlFile::WriteNodeHierarchy(*eventNode, TEXT(""), xml);

        return XmlFile->LoadFile(xml, EConstructMethod::ConstructFromBuffer);
    }

    return false;
}

FString UVH_COTEvent::ToXML() const
{
    FString xmlString = TEXT("");
    if (XmlFile.IsValid() && XmlFile->SaveToString(xmlString))
	{
        return xmlString;
    }

    UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTEvent::ToXML | XmlFile->Save returned false | returning false"));
    return TEXT("");
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UVH_COTEvent::Initialize()
{
    if (!XmlFile.IsValid())
    {
        XmlFile = MakeShared<FXmlFile>(TEXT("<event version=\"2.0\"></event>"), EConstructMethod::ConstructFromBuffer);

        // set default values
        SetAttribute(TEXT("how"), TEXT("h-g-i-g-o"));
    }
}