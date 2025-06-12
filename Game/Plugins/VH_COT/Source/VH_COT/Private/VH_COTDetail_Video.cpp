// Required includes
#include "VH_COTDetail_Video.h"
#include "VH_COT.h"

// Engine includes
#include "Runtime/XmlParser/Public/XmlNode.h"
#include "Runtime/Core/Public/Misc/Guid.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVH_COTDetail_Video::UVH_COTDetail_Video() :
	RawPath(TEXT("")),
	Address(TEXT("")),
	Alias(TEXT("")),
	BufferTime(-1),
	IgnoreEmbeddedKLV(false),
	NetworkTimeout(0),
	Path(TEXT("")),
	Port(-1),
	Protocol(ESchemeTypeEnum::EST_UNKNOWN),
	RoverPort(-1),
	RTSPReliable(false),
	UID(TEXT(""))
{
	UID = FName(*FGuid::NewGuid().ToString());
}

// ---------------------------------
// --- Public Methods
// ---------------------------------

FString UVH_COTDetail_Video::GetVideoURL() const
{
	FString videoURL = UVH_URI::GetStringFromProtocol(Protocol) + TEXT("://");
	videoURL += Address;
	videoURL += (Port >= 0) ? FString::Printf(TEXT(":%d"), Port) : TEXT("");

	FString pathDir = Path;
	if (pathDir.StartsWith(TEXT("/")))
	{
		pathDir.RemoveFromStart(TEXT("/"));
	}

	videoURL += Path;

	return videoURL;
}

bool UVH_COTDetail_Video::PopulateFromURL(FString url, UVH_COTDetail_Video*& outVideo)
{
	UVH_URI* uri = NewObject<UVH_URI>();

	if (!url.IsEmpty() && uri != nullptr)
	{
		uri->SetFromString(url);

		Address = uri->GetHost();
		Alias = uri->GetFilename();
		Path = uri->GetAbsolutePath();
		Port = uri->GetPort();
		Protocol = uri->GetScheme();

		BufferTime = -1;
		IgnoreEmbeddedKLV = false;
		NetworkTimeout = 3000;
		RoverPort = -1;
		RTSPReliable = false;

		outVideo = this;

		return true;
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("VH_COTDetail_Video -- Error: attempting to populate a COTDetail_Video from an empty URL or URI is nullptr"));
	}

	return false;
}

bool UVH_COTDetail_Video::PopulateFromXML(const FXmlNode* xmlNode)
{
	if (xmlNode != nullptr)
	{
		if (xmlNode->FindChildNode(TEXT("ConnectionEntry")) != nullptr)
		{
			const FXmlNode* connectionEntry = xmlNode->FindChildNode(TEXT("ConnectionEntry"));

			if (!connectionEntry->GetAttribute(TEXT("address")).IsEmpty())
			{
				Address = connectionEntry->GetAttribute(TEXT("address"));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"address\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("alias")).IsEmpty())
			{
				Alias = connectionEntry->GetAttribute(TEXT("alias"));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"alias\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("bufferTime")).IsEmpty())
			{
				BufferTime = FCString::Atoi(*connectionEntry->GetAttribute(TEXT("bufferTime")));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"bufferTime\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("ignoreEmbeddedKLV")).IsEmpty())
			{
				IgnoreEmbeddedKLV = FCString::ToBool(*connectionEntry->GetAttribute(TEXT("ignoreEmbeddedKLV")));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"ignoreEmbeddedKLV\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("networkTimeout")).IsEmpty())
			{
				NetworkTimeout = FCString::Atoi(*connectionEntry->GetAttribute(TEXT("networkTimeout")));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"networkTimeout\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("path")).IsEmpty())
			{
				Path = connectionEntry->GetAttribute(TEXT("path"));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"path\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("port")).IsEmpty())
			{
				Port = FCString::Atoi(*connectionEntry->GetAttribute(TEXT("port")));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"port\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("protocol")).IsEmpty())
			{
				FString protocolString = connectionEntry->GetAttribute(TEXT("protocol"));
				Protocol = UVH_URI::UVH_URI::GetProtocolFromString(protocolString);
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"protocol\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("roverPort")).IsEmpty())
			{
				RoverPort = FCString::Atoi(*connectionEntry->GetAttribute(TEXT("roverPort")));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"roverPort\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("rtspReliable")).IsEmpty())
			{
				RTSPReliable = FCString::ToBool(*connectionEntry->GetAttribute(TEXT("rtspReliable")));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"rtspReliable\" is empty"));
			}

			if (!connectionEntry->GetAttribute(TEXT("uid")).IsEmpty())
			{
				UID = FName(*connectionEntry->GetAttribute(TEXT("uid")));
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- Attribute \"uid\" is empty"));
			}
		}
		else
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- ERROR: ConnectionEntry child node not found"));

			return false;
		}

		return true;
	}
	else
	{
		FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXML() -- ERROR: The xmlNode is null"));
	}

	return false;
}

bool UVH_COTDetail_Video::PopulateFromXMLRest(const FXmlNode* xmlNode)
{
	if (xmlNode != nullptr)
	{
		if (xmlNode->GetTag().Equals("feed"))
		{
			if (xmlNode->FindChildNode(TEXT("address")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("address"))->GetContent().IsEmpty())
				{
					Address = xmlNode->FindChildNode(TEXT("address"))->GetContent();
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"address\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"address\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("alias")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("alias"))->GetContent().IsEmpty())
				{
					Alias = xmlNode->FindChildNode(TEXT("alias"))->GetContent();
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"alias\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"alias\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("buffer")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("buffer"))->GetContent().IsEmpty())
				{
					BufferTime = FCString::Atoi(*xmlNode->FindChildNode(TEXT("buffer"))->GetContent());
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"buffer\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to\"buffer\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("ignoreEmbeddedKLV")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("ignoreEmbeddedKLV"))->GetContent().IsEmpty())
				{
					IgnoreEmbeddedKLV = FCString::ToBool(*xmlNode->FindChildNode(TEXT("ignoreEmbeddedKLV"))->GetContent());
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"ignoreEmbeddedKLV\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"ignoreEmbeddedKLV\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("timeout")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("timeout"))->GetContent().IsEmpty())
				{
					NetworkTimeout = FCString::Atoi(*xmlNode->FindChildNode(TEXT("timeout"))->GetContent());
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"timeout\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"timeout\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("path")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("path"))->GetContent().IsEmpty())
				{
					Path = xmlNode->FindChildNode(TEXT("path"))->GetContent();
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"path\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"path\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("port")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("port"))->GetContent().IsEmpty())
				{
					Port = FCString::Atoi(*xmlNode->FindChildNode(TEXT("port"))->GetContent());
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"port\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"port\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("protocol")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("protocol"))->GetContent().IsEmpty())
				{
					FString protocolString = xmlNode->FindChildNode(TEXT("protocol"))->GetContent();
					Protocol = UVH_URI::UVH_URI::GetProtocolFromString(protocolString);
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"protocol\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"protocol\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("roverPort")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("roverPort"))->GetContent().IsEmpty())
				{
					RoverPort = FCString::Atoi(*xmlNode->FindChildNode(TEXT("roverPort"))->GetContent());
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"roverPort\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"roverPort\" child node is null"));
			}

			if (const FXmlNode* node = xmlNode->FindChildNode(TEXT("rtspReliable")))
			{
				if (!node->GetContent().IsEmpty())
				{
					RTSPReliable = FCString::Atoi(*node->GetContent()) != 0;
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"rtspReliable\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"rtspReliable\" child node is null"));
			}

			if (xmlNode->FindChildNode(TEXT("uid")) != nullptr)
			{
				if (!xmlNode->FindChildNode(TEXT("uid"))->GetContent().IsEmpty())
				{
					UID = FName(*xmlNode->FindChildNode(TEXT("uid"))->GetContent());
				}
				else
				{
					FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- Child node \"uid\" is empty"));
				}
			}
			else
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Reference to \"uid\" child node is null"));
			}
		}
		else
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: Feed tag not found, unable to parse download rest request XML"));

			return false;
		}

		return true;
	}
	else
	{
		FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UVH_COTDetail_Video::PopulateFromXMLRest() -- ERROR: The xmlNode is null"));
	}

	return false;
}

void UVH_COTDetail_Video::PopulateFromDB(const SpatialiteResult& result)
{
	Address = UDatabase_Spatialite::GetString(TEXT("address"), result);

	Alias = UDatabase_Spatialite::GetString(TEXT("alias"), result);

	BufferTime = UDatabase_Spatialite::GetInteger(TEXT("bufferTime"), result);

	IgnoreEmbeddedKLV = UDatabase_Spatialite::GetBool(TEXT("ignoreEmbeddedKLV"), result);

	NetworkTimeout = UDatabase_Spatialite::GetInteger(TEXT("networkTimeout"), result);

	Path = UDatabase_Spatialite::GetString(TEXT("path"), result);

	Port = UDatabase_Spatialite::GetInteger(TEXT("port"), result);

	Protocol = UVH_URI::GetProtocolFromString(UDatabase_Spatialite::GetString(TEXT("protocol"), result));

	RoverPort = UDatabase_Spatialite::GetInteger(TEXT("roverPort"), result);

	RTSPReliable = UDatabase_Spatialite::GetBool(TEXT("rtspReliable"), result);

	UID = FName(*UDatabase_Spatialite::GetString(TEXT("uid"), result));
}

void UVH_COTDetail_Video::AddToDatabase(UDatabase_Spatialite* database)
{
	FString query = FString::Printf(TEXT("insert into videos (address, alias, bufferTime, ignoreEmbeddedKLV, networkTimeout, path, port, protocol, roverPort, rtspReliable, uid) values (\"%s\", \"%s\", \"%d\", \"%d\", \"%d\", \"%s\", \"%d\", \"%s\", \"%d\", \"%d\", \"%s\")"), *Address, *Alias, BufferTime, (int32)IgnoreEmbeddedKLV, NetworkTimeout, *Path, Port, *UVH_URI::GetStringFromProtocol(Protocol), RoverPort, (int32)RTSPReliable, *UID.ToString());
	database->SyncQuery(query);
}

void UVH_COTDetail_Video::RemoveFromDatabase(UDatabase_Spatialite* database)
{
	FString query = FString::Printf(TEXT("delete from videos where uid = \"%s\""), *UID.ToString());
	database->SyncQuery(query);
}

FString UVH_COTDetail_Video::ToXML() const
{
	FString ignoreEmbeddedKLVString = IgnoreEmbeddedKLV ? TEXT("true") : TEXT("false");
	FString xml = TEXT("<__video>");

	xml += TEXT("<ConnectionEntry");
	xml += FString::Printf(TEXT(" protocol=\"%s\""), *UVH_URI::GetStringFromProtocol(Protocol));
	xml += FString::Printf(TEXT(" path=\"%s\""), *Path);
	xml += FString::Printf(TEXT(" address=\"%s\""), *Address);
	xml += FString::Printf(TEXT(" port=\"%d\""), Port);
	xml += FString::Printf(TEXT(" uid=\"%s\""), *UID.ToString());
	xml += FString::Printf(TEXT(" alias=\"%s\""), *Alias);
	xml += FString::Printf(TEXT(" roverPort=\"%d\""), RoverPort);
	xml += FString::Printf(TEXT(" rtspReliable=\"%d\""), (int32)RTSPReliable);
	xml += FString::Printf(TEXT(" ignoreEmbeddedKLV=\"%s\""), *ignoreEmbeddedKLVString);
	xml += FString::Printf(TEXT(" networkTimeout=\"%d\""), NetworkTimeout);
	xml += FString::Printf(TEXT(" bufferTime=\"%d\""), BufferTime);
	xml += TEXT("/>");

	xml += TEXT("</__video>");

	return xml;
}

// ---------------------------------
// --- Debug/Testing
// ---------------------------------

FString UVH_COTDetail_Video::ToString() const
{
	FString ignoreEmbeddedKLVString = IgnoreEmbeddedKLV ? TEXT("true") : TEXT("false");
	FString rtspReliable = RTSPReliable ? TEXT("true") : TEXT("false");

	return FString::Printf(TEXT("Address: %s, Alias: %s, Buffer Time: %d, Ignore Embedded KLV: %s, Network Timeout: %d, Path: %s, Port: %d, Protocol: %s, RoverPort: %d, RTSPReliable: %s, UID: %s"), *Address, *Alias, BufferTime, *ignoreEmbeddedKLVString, NetworkTimeout, *Path, Port, *UVH_URI::GetStringFromProtocol(Protocol), RoverPort, *rtspReliable, *UID.ToString());
}