// Required Includes
#include "VH_COTConnectionInfo.h"
#include "VH_COT.h"

// Engine Includes
#include "SocketSubsystem.h"
#include "Async/Async.h"
#include "XmlFile.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Base64.h"
#include "Misc/CommandLine.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "Developer_Subsystem_Core.h"

// Module Includes
#include "VH_COTManager.h"

#include "commo.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVH_COTConnectionInfo::UVH_COTConnectionInfo() :
	bConnected(false),
	Interface(nullptr),
	bConnecting(false),
	bDisconnecting(false)
{
	MessageTypes.Add(ECOTMessageTypes::ECMT_Chat);
	MessageTypes.Add(ECOTMessageTypes::ECMT_SituationalAwareness);
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UVH_COTConnectionInfo* UVH_COTConnectionInfo::CreateNewConnectionInfo(const FString& rootDirectory)
{
	FString fullPathOnDisk = rootDirectory;

	FXmlFile xmlFile;

	fullPathOnDisk += TEXT("/connection.xml");

	if (FPaths::FileExists(*fullPathOnDisk))
	{
		xmlFile.LoadFile(fullPathOnDisk);
	}

	if (FPaths::FileExists(*fullPathOnDisk))
	{
		if (xmlFile.IsValid())
		{
			FXmlNode* rootNode = xmlFile.GetRootNode();

			UVH_COTConnectionInfo* connectionInfo = NewObject<UVH_COTConnectionInfo>();

			connectionInfo->RootDirectory = rootDirectory;

			connectionInfo->PopulateFromXML(rootNode);

			return connectionInfo;
		}

		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::CreateNewConnectionInfo | invalid file | %s"), *fullPathOnDisk);
	}

	return nullptr;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UVH_COTConnectionInfo::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

// ---------------------------------
// --- API
// ---------------------------------

UVH_COTConnectionInfo* UVH_COTConnectionInfo::Copy() const
{
	UVH_COTConnectionInfo* connectionInfoCopy = DuplicateObject(this, GetOuter());
	
	return connectionInfoCopy;
}

FString UVH_COTConnectionInfo::GetCommoEndpoint() const
{
	FString endpoint = TEXT("");

	if (ConnectionProtocol == EConnectionProtocolTypes::E_SSL)
	{
		endpoint += TEXT("ssl");
	}
	else if (ConnectionProtocol == EConnectionProtocolTypes::E_QUIC)
	{
		endpoint += TEXT("quic");
	}
	else
	{
		endpoint += TEXT("tcp");
	}

	endpoint = FString::Printf(TEXT("%s:%s:%d"), *endpoint, *Host, Port);

	return endpoint;
}

void UVH_COTConnectionInfo::HandleLDAPCredentials(const FString& ldapUsername, const FString& ldapPassword)
{
	UVH_COTManager* cotManager = UVH_COTManager::Get();
	if (cotManager == nullptr)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- cotManager is nullptr | aborting"));
		return;
	}

	CreatePEMs();

	Username = ldapUsername;
	Password = ldapPassword;

	FString url = FString::Printf(TEXT("https://%s:8446/Marti/api/tls/config"), *Host);
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(GetCommoEndpoint(), url);

	request->SetHeader(TEXT("Authorization"), GetAuthorizationHeaderValue());

	request->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		if (bSucceeded)
		{
			FString xml = BytesToString(response->GetContent().GetData(), response->GetContent().Num());
			HandleLDAPConfigResponse(xml);
		}

		DestroyCounter.Decrement();
	});

	request->ProcessRequest();
}

void UVH_COTConnectionInfo::Disconnect(bool bSynchronous)
{
	if (bSynchronous)
	{
		if (Interface != nullptr && !bDisconnecting)
		{
			atakmap::commoncommo::Commo* commo = GetCommo();
			if (commo == nullptr)
			{
				UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::Disconnect | commo is nullptr | aborting"));
				return;
			}

			bDisconnecting = true;

			switch (ConnectionType)
			{
			case ECOTConnectionType::ECT_Broadcast:
			{
				if (atakmap::commoncommo::PhysicalNetInterface* interface = static_cast<atakmap::commoncommo::PhysicalNetInterface*>(Interface))
				{
					commo->removeBroadcastInterface(interface);
				}
			}
			break;

			case ECOTConnectionType::ECT_Inbound:
			{
				if (atakmap::commoncommo::PhysicalNetInterface* interface = static_cast<atakmap::commoncommo::PhysicalNetInterface*>(Interface))
				{
					commo->removeInboundInterface(interface);
				}
			}
			break;

			case ECOTConnectionType::ECT_Stream:
			{
				if (atakmap::commoncommo::StreamingNetInterface* interface = static_cast<atakmap::commoncommo::StreamingNetInterface*>(Interface))
				{
					commo->removeStreamingInterface(interface);
				}
			}
			break;

			default:
				UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::Disconnect | unknown connection type | %d"), (int32)ConnectionType);
				break;
			}

			Interface = nullptr;

			bConnected = false;

			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					DestroyCounter.Decrement();
					return;
				}

				OnReceivedConnectionStatusUpdate.Broadcast(this);

				DestroyCounter.Decrement();
			});

			bDisconnecting = false;
		}
	}
	else
	{
		Async(EAsyncExecution::ThreadPool, [this]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}

			Disconnect(true);

			DestroyCounter.Decrement();
		});
	}
}

void UVH_COTConnectionInfo::CreateConnection(bool bSynchronous)
{
	if (IsDisconnected())
	{
		if (bSynchronous)
		{
			switch (ConnectionType)
			{
			case ECOTConnectionType::ECT_Broadcast:
				// todo ohg | implement
				UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::CreateConnection | ECT_Broadcast is not implemented"))
					break;

			case ECOTConnectionType::ECT_Inbound:
				// todo ohg | implement
				UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::CreateConnection | ECT_Inbound is not implemented"))
					break;

			case ECOTConnectionType::ECT_Stream:
				CreateConnection_Stream();
				break;
			}
		}
		else
		{
			Async(EAsyncExecution::ThreadPool, [this]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					DestroyCounter.Decrement();
					return;
				}

				CreateConnection(true);

				DestroyCounter.Decrement();
			});
		}
	}
}

bool UVH_COTConnectionInfo::IsDisconnected() const
{
	return Interface == nullptr && !bConnecting;
}

void UVH_COTConnectionInfo::PopulateFromXML(FXmlNode* rootNode)
{
	DisplayName = rootNode->FindChildNode(TEXT("displayName"))->GetContent();

	bConnectAtInitialization = rootNode->FindChildNode("connectAtInitialization")->GetContent().Equals(TEXT("true"), ESearchCase::IgnoreCase);

	FString type = rootNode->FindChildNode(TEXT("connectionType"))->GetContent();
	if (type.Equals(TEXT("stream"), ESearchCase::IgnoreCase))
	{
		ConnectionType = ECOTConnectionType::ECT_Stream;
	}
	else if (type.Equals(TEXT("inbound"), ESearchCase::IgnoreCase))
	{
		ConnectionType = ECOTConnectionType::ECT_Inbound;
	}
	else if (type.Equals(TEXT("broadcast"), ESearchCase::IgnoreCase))
	{
		ConnectionType = ECOTConnectionType::ECT_Broadcast;
	}

	Host = rootNode->FindChildNode(TEXT("host"))->GetContent();
	MulticastAddress = rootNode->FindChildNode(TEXT("multicastAddress"))->GetContent();
	Port = FCString::Atoi(*rootNode->FindChildNode(TEXT("port"))->GetContent());

	if (FXmlNode* messageTypesNode = rootNode->FindChildNode(TEXT("messageTypes")))
	{
		TArray<FXmlNode*> messageTypeNodes = messageTypesNode->GetChildrenNodes();
		for (FXmlNode* typeNode : messageTypeNodes)
		{
			if (typeNode->GetContent().Equals(TEXT("situationalAwareness"), ESearchCase::IgnoreCase))
			{
				MessageTypes.AddUnique(ECOTMessageTypes::ECMT_SituationalAwareness);
			}
			else if (typeNode->GetContent().Equals(TEXT("chat"), ESearchCase::IgnoreCase))
			{
				MessageTypes.AddUnique(ECOTMessageTypes::ECMT_Chat);
			}
		}
	}
	
	auto getNodeContent = [](FXmlNode* rootNode, const FString& nodeName)
	{
		if (FXmlNode* node = rootNode->FindChildNode(nodeName))
		{
			return node->GetContent();
		}

		return FString();
	};

	ClientCertificateName = getNodeContent(rootNode, TEXT("clientCertificateName"));
	ClientCertificatePassword = getNodeContent(rootNode, TEXT("clientCertificatePassword"));
	CertificateAuthorityName = getNodeContent(rootNode, TEXT("certificateAuthorityName"));
	CertificateAuthorityPassword = getNodeContent(rootNode, TEXT("certificateAuthorityPassword"));
	bEnrollForCert = getNodeContent(rootNode, TEXT("enrollForCertificateWithTrust")).Equals(TEXT("true"), ESearchCase::IgnoreCase);
	bQUIC = getNodeContent(rootNode, TEXT("quic")).Equals(TEXT("true"), ESearchCase::IgnoreCase);
	Username = getNodeContent(rootNode, TEXT("username"));
	Password = getNodeContent(rootNode, TEXT("password"));

	ConnectionProtocol = EConnectionProtocolTypes::E_TCP;
	FXmlNode* protocolNode = rootNode->FindChildNode(TEXT("connectionProtocolType"));
	if (protocolNode != nullptr)
	{
		FString protocol = protocolNode->GetContent();
		if (protocol.Equals(TEXT("ssl"), ESearchCase::IgnoreCase))
		{
			ConnectionProtocol = EConnectionProtocolTypes::E_SSL;
		}
		else if (protocol.Equals(TEXT("tcp"), ESearchCase::IgnoreCase))
		{
			ConnectionProtocol = EConnectionProtocolTypes::E_TCP;
		}
		else if (protocol.Equals(TEXT("quic"), ESearchCase::IgnoreCase))
		{
			ConnectionProtocol = EConnectionProtocolTypes::E_QUIC;
		}
	}
}

FString UVH_COTConnectionInfo::ToXML() const
{
	FString xml = TEXT("<connection>\n");
	xml += FString::Printf(TEXT("<displayName>%s</displayName>\n"), *DisplayName);
	xml += FString::Printf(TEXT("<connectAtInitialization>%s</connectAtInitialization>\n"), bConnectAtInitialization ? TEXT("true") : TEXT("false"));

	FString connectionType = TEXT("");
	switch (ConnectionType)
	{
		case ECOTConnectionType::ECT_Broadcast:
			connectionType = TEXT("broadcast");
			break;

		case ECOTConnectionType::ECT_Inbound:
			connectionType = TEXT("inbound");
			break;

		case ECOTConnectionType::ECT_Stream:
			connectionType = TEXT("stream");
			break;

		default:
			break;
	}

	xml += FString::Printf(TEXT("<connectionType>%s</connectionType>\n"), *connectionType);

	FString connectionProtocol = TEXT("");
	switch (ConnectionProtocol)
	{
		case EConnectionProtocolTypes::E_TCP:
			connectionProtocol = TEXT("tcp");
			break;

		case EConnectionProtocolTypes::E_SSL:
			connectionProtocol = TEXT("ssl");
			break;

		case EConnectionProtocolTypes::E_QUIC:
			connectionProtocol = TEXT("quic");
			break;
	}
	
	xml += FString::Printf(TEXT("<connectionProtocolType>%s</connectionProtocolType>\n"), *connectionProtocol);

	xml += FString::Printf(TEXT("<host>%s</host>\n"), *Host);
	xml += FString::Printf(TEXT("<multicastAddress>%s</multicastAddress>\n"), *MulticastAddress);
	xml += FString::Printf(TEXT("<port>%d</port>\n"), Port);

	xml += TEXT("<messageTypes>\n");
	for (const ECOTMessageTypes& messageType : MessageTypes)
	{
		FString messageTypeString = TEXT("");
		switch (messageType)
		{
			case ECOTMessageTypes::ECMT_SituationalAwareness:
				messageTypeString = TEXT("situationalAwareness");
				break;

			case ECOTMessageTypes::ECMT_Chat:
				messageTypeString = TEXT("chat");
				break;

			default:
				break;
		}

		xml += FString::Printf(TEXT("<messageType>%s</messageType>\n"), *messageTypeString);
	}
	xml += TEXT("</messageTypes>\n");

	xml += FString::Printf(TEXT("<clientCertificateName>%s</clientCertificateName>\n"), *ClientCertificateName);
	xml += FString::Printf(TEXT("<clientCertificatePassword>%s</clientCertificatePassword>\n"), *ClientCertificatePassword);
	xml += FString::Printf(TEXT("<certificateAuthorityName>%s</certificateAuthorityName>\n"), *CertificateAuthorityName);
	xml += FString::Printf(TEXT("<certificateAuthorityPassword>%s</certificateAuthorityPassword>\n"), *CertificateAuthorityPassword);
	xml += FString::Printf(TEXT("<enrollForCertificateWithTrust>%s</enrollForCertificateWithTrust>\n"), bEnrollForCert ? TEXT("true") : TEXT("false"));
	xml += FString::Printf(TEXT("<quic>%s</quic>\n"), bQUIC ? TEXT("true") : TEXT("false"));
	xml += FString::Printf(TEXT("<username>%s</username>\n"), *Username);
	xml += FString::Printf(TEXT("<password>%s</password>\n"), *Password);
	xml += TEXT("</connection>");

	return xml;
}

void UVH_COTConnectionInfo::WriteXMLToFile(const FString& rootDirectory) const
{
	FString fullPathOnDisk = rootDirectory;

	FString xml = ToXML();

	fullPathOnDisk += TEXT("/connection.xml");

	FFileHelper::SaveStringToFile(xml, *fullPathOnDisk);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UVH_COTConnectionInfo::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

void UVH_COTConnectionInfo::HandleLDAPSignClientResponse(const FString& fullPathToP12, const FString& privateKey, const FString& keystorePassword)
{
	IFileManager& fileManager = IFileManager::Get();

	atakmap::commoncommo::Commo* commo = GetCommo();
	if (commo == nullptr)
	{
		fileManager.Delete(*fullPathToP12);

		bConnecting = false;

		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::HandleLDAPSignClientResponse | commo is nullptr | aborting"));
		return;
	}

	FString openSSLPath = FPaths::Combine(FPaths::RootDir(), TEXT("Tools"), TEXT("openssl.exe"));
	FString args = FString::Printf(TEXT("pkcs12 -in %s -out %s/temp.pem -passin pass:%s"), *fullPathToP12, *RootDirectory, TEXT("atakatak"));
	FProcHandle procHandle = FPlatformProcess::CreateProc(*openSSLPath, *args, true, true, true, nullptr, 0, nullptr, nullptr);
	FPlatformProcess::WaitForProc(procHandle);

	if (!FPaths::FileExists(*(FString::Printf(TEXT("%s/temp.pem"), *RootDirectory))))
	{
		fileManager.Delete(*fullPathToP12);

		bConnecting = false;

		return;
	}

	TArray<FString> fileArray;
	FFileHelper::LoadFileToStringArray(fileArray, *FString::Printf(TEXT("%s/temp.pem"), *RootDirectory));

	FString certPem;
	FString caPem;
	TArray<FString> caPemArray;
	int32 caPemIndex = 0;

	FString alias = TEXT("");
	bool bAdd = false;

	for (FString line : fileArray)
	{
		if (line.Contains(TEXT("friendlyName"), ESearchCase::IgnoreCase))
		{
			TArray<FString> splitArray;
			line.ParseIntoArray(splitArray, TEXT(" "));

			if (splitArray.Num() == 2)
			{
				alias = splitArray[1];
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::HandleLDAPSignClientResponse | splitArray.Num() != 2"));
			}
		}

		if (bAdd && line.Contains(TEXT("Bag Attributes")))
		{
			bAdd = false;

			if (!alias.Equals(TEXT("signedCert"), ESearchCase::IgnoreCase))
			{
				caPemArray.Add(caPem);

				caPem = TEXT("");
			}
		}

		if (line.Contains(TEXT("begin certificate"), ESearchCase::IgnoreCase))
		{
			line += TEXT("\n");
			bAdd = true;
		}
		else if (line.Contains(TEXT("end certificate"), ESearchCase::IgnoreCase))
		{
			line = TEXT("\n") + line;
		}

		if (bAdd)
		{
			if (alias.Equals(TEXT("signedCert"), ESearchCase::IgnoreCase))
			{
				certPem += line;
			}
			else
			{
				caPem += line;
			}
		}
	}

	if (!alias.Equals(TEXT("signedCert"), ESearchCase::IgnoreCase))
	{
		caPemArray.Add(caPem);
		caPem = TEXT("");
	}

	const char** caPemCharArray = new const char*[caPemArray.Num()];

	for (int32 i = 0; i < caPemArray.Num(); i++)
	{
		std::string tempLine = std::string(TCHAR_TO_ANSI(*caPemArray[i]));

		char* lineCharPtr = new char[tempLine.size() + 1];
		memcpy(lineCharPtr, tempLine.c_str(), tempLine.size() + 1);

		caPemCharArray[i] = lineCharPtr;
	}

	FString encodedKeystore = FString(commo->generateKeystoreCryptoString(TCHAR_TO_ANSI(*certPem), caPemCharArray, caPemArray.Num(), TCHAR_TO_ANSI(*privateKey), TCHAR_TO_ANSI(*keystorePassword), "TAK Client Cert"));

	TArray<uint8> certBytes;
	FBase64::Decode(encodedKeystore, certBytes);

	FFileHelper::SaveArrayToFile(certBytes, *(RootDirectory / TEXT("ClientCert.p12")));

	fileManager.Delete(*fullPathToP12);
	fileManager.Delete(*(RootDirectory / TEXT("temp.pem")));

	AsyncTask(ENamedThreads::GameThread, [this, keystorePassword]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		// update properties and xml file
		ClientCertificateName = TEXT("ClientCert.p12");
		ClientCertificatePassword = keystorePassword;

		if (CertificateAuthorityName.IsEmpty())
		{
			CertificateAuthorityName = TEXT("ClientCert.p12");
			CertificateAuthorityPassword = keystorePassword;
		}

		bConnecting = false;

		WriteXMLToFile(RootDirectory);

		CreateConnection();

		DestroyCounter.Decrement();
	});
}

void UVH_COTConnectionInfo::HandleLDAPConfigResponse(const FString& originalXML)
{
	UVH_COTManager* cotManager = UVH_COTManager::Get();
	if (cotManager == nullptr)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::HandleLDAPConfigResponse | cotManager is nullptr | aborting"));

		bConnecting = false;

		return;
	}

	atakmap::commoncommo::Commo* commo = GetCommo();
	if (commo == nullptr)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::HandleLDAPConfigResponse | commo is nullptr | aborting"));

		bConnecting = false;

		return;
	}

	FString xml = vh_cot::ConvertFromCommoString(originalXML);
	xml = xml.Replace(TEXT("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>"), TEXT(""));

	FXmlFile xmlFile(xml, EConstructMethod::ConstructFromBuffer);
	if (xmlFile.IsValid())
	{
		FString keystorePassword = FGuid::NewGuid().ToString();
		char* privateKey = commo->generateKeyCryptoString(TCHAR_TO_ANSI(*keystorePassword), 4096);

		if (privateKey == nullptr)
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::HandleLDAPConfigResponse | generateKeyCryptoString was nullptr | aborting"));

			bConnecting = false;

			return;
		}

		TMap<FString, FString> dnEntries;
		dnEntries.Add(TEXT("CN"), Username);

		FXmlNode* rootNode = xmlFile.GetRootNode();
		FXmlNode* nameEntryNode = rootNode->FindChildNode(TEXT("nameEntries"));
		TArray<FXmlNode*> nameEntryNodes = nameEntryNode->GetChildrenNodes();
		for (FXmlNode* node : nameEntryNodes)
		{
			dnEntries.Add(node->GetAttribute(TEXT("name")), node->GetAttribute(TEXT("value")));
		}

		const char** dnEntryKeys = new const char*[dnEntries.Num()];
		const char** dnEntryValues = new const char*[dnEntries.Num()];

		int32 index = 0;
		for (const TPair<FString, FString>& entry : dnEntries)
		{
			std::string tempKey = std::string(TCHAR_TO_ANSI(*entry.Key));
			std::string tempValue = std::string(TCHAR_TO_ANSI(*entry.Value));

			char* key = new char[tempKey.size() + 1];
			memcpy(key, tempKey.c_str(), tempKey.size() + 1);

			char* value = new char[tempValue.size() + 1];
			memcpy(value, tempValue.c_str(), tempValue.size() + 1);


			dnEntryKeys[index] = key;
			dnEntryValues[index] = value;

			index++;
		}

		FString signingRequest = FString(commo->generateCSRCryptoString(dnEntryKeys, dnEntryValues, dnEntries.Num(), privateKey, TCHAR_TO_ANSI(*keystorePassword)));

		signingRequest = signingRequest.Replace(TEXT("-----BEGIN CERTIFICATE REQUEST-----\n"), TEXT(""));
		signingRequest = signingRequest.Replace(TEXT("\n-----END CERTIFICATE REQUEST-----"), TEXT(""));

		FString url = FString::Printf(TEXT("https://%s:8446/Marti/api/tls/signClient?clientUid=%s"), *Host, *cotManager->GetSelfUID().ToString());
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(GetCommoEndpoint(), url, TEXT("POST"), TEXT("application/octet-stream"));

		FString value = FString::Printf(TEXT("%s:%s"), *Username, *Password);
		request->AppendToHeader(TEXT("Authorization"), GetAuthorizationHeaderValue());

		request->SetContentAsString(signingRequest);

		request->OnProcessRequestComplete().BindLambda([this, privateKey, keystorePassword](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}

			if (bSucceeded)
			{
				FString fullPathToP12 = FString::Printf(TEXT("%s/temp.p12"), *RootDirectory);
				FFileHelper::SaveArrayToFile(response->GetContent(), *fullPathToP12);

				HandleLDAPSignClientResponse(fullPathToP12, privateKey, keystorePassword);
			}

			DestroyCounter.Decrement();
		});

		request->ProcessRequest();
	}
	else
	{
		bConnecting = false;

		ConnectionError = TEXT("Authentication error");

		Username = TEXT("");
		Password = TEXT("");
	}
}

void UVH_COTConnectionInfo::CreateConnection_Stream()
{
	atakmap::commoncommo::Commo* commo = GetCommo();
	if (commo == nullptr)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::CreateConnection_Stream | commo is nullptr | aborting"));
		return;
	}

	bConnecting = true;

	if (bEnrollForCert && ClientCertificateName.IsEmpty())
	{
		if (Username.IsEmpty() || Password.IsEmpty())
		{
			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					DestroyCounter.Decrement();
					return;
				}

				UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get();
				UVH_COTManager* cotManager = UVH_COTManager::Get();

				if (subsystem != nullptr && cotManager != nullptr)
				{
					cotManager->GetLDAPCredentials(this);
				}
				else
				{
					UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::CreateConnection_Stream | cotManager and/or gameInstance is nullptr | aborting"));
				}

				DestroyCounter.Decrement();
			});
		}
		else
		{
			HandleLDAPCredentials(Username, Password);
		}

		return;
	}

	TArray<uint8> certContent;
	if (!ClientCertificateName.IsEmpty() && !FFileHelper::LoadFileToArray(certContent, *(RootDirectory / ClientCertificateName)))
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVHT_COTManager::CreateConnection_Stream | couldn't load certificate file | %s"), *ClientCertificateName);

		ConnectionError = TEXT("couldn't load certificate file");
		OnReceivedConnectionError.Broadcast(this);

		return;
	}

	TArray<uint8> caCertContent;
	if (!CertificateAuthorityName.IsEmpty() && !FFileHelper::LoadFileToArray(caCertContent, *(RootDirectory / CertificateAuthorityName)))
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVHT_COTManager::CreateConnection_Stream | couldn't load certificate authority file | %s"), *CertificateAuthorityName);

		ConnectionError = TEXT("couldn't load certificate authority file");
		OnReceivedConnectionError.Broadcast(this);

		return;
	}

	CreatePEMs();

	if (!CertificateAuthorityName.IsEmpty())
	{
		// check if certificate is expired
		void* readPipe = nullptr;
		void* writePipe = nullptr;
		FPlatformProcess::CreatePipe(readPipe, writePipe);

		FString openSSLPath = FPaths::Combine(FPaths::RootDir(), TEXT("Tools"), TEXT("openssl.exe"));
		FString args = FString::Printf(TEXT("x509 -in %s -noout -checkend 86400"), *(RootDirectory / CertificateAuthorityName));
		FProcHandle procHandle = FPlatformProcess::CreateProc(*openSSLPath, *args, true, true, true, nullptr, 0, nullptr, writePipe);
		FPlatformProcess::WaitForProc(procHandle);

		int32 returnCode;
		if (FPlatformProcess::GetProcReturnCode(procHandle, &returnCode))
		{
			if (returnCode == 0)
			{
				ConnectionError = TEXT("certificate expired");
				OnReceivedConnectionError.Broadcast(this);
				return;
			}
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("-- unable to check if certificate is expired | %s"), *DisplayName);
		}
	}

	// create connection via Commo
	TArray<atakmap::commoncommo::CoTMessageType> messageTypes;
	messageTypes.Add(atakmap::commoncommo::CoTMessageType::SITUATIONAL_AWARENESS);
	messageTypes.Add(atakmap::commoncommo::CoTMessageType::CHAT);

	// check for bad multihome launch parameter
	TCHAR home[256] = TEXT("");
	if (FParse::Value(FCommandLine::Get(), TEXT("MULTIHOME="), home, UE_ARRAY_COUNT(home)))
	{
		if (!UDeveloper_Statics::VerifyMultihome())
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::CreateConnection_Stream | invalid IP for multihome launch parameter: %s"), home);
			return;
		}
	}
	
	atakmap::commoncommo::netinterfaceenums::StreamingTransport protocol;
	switch (ConnectionProtocol)
	{
		case EConnectionProtocolTypes::E_SSL:
			protocol = atakmap::commoncommo::netinterfaceenums::StreamingTransport::TRANSPORT_SSL;
			break;

		case EConnectionProtocolTypes::E_TCP:
			protocol = atakmap::commoncommo::netinterfaceenums::StreamingTransport::TRANSPORT_TCP;
			break;

		case EConnectionProtocolTypes::E_QUIC:
			protocol = atakmap::commoncommo::netinterfaceenums::StreamingTransport::TRANSPORT_QUIC;
			break;

		default:
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTConnectionInfo::CreateConnection_Stream | unknown protocol | defaulting to SSL"));
			protocol = atakmap::commoncommo::netinterfaceenums::StreamingTransport::TRANSPORT_SSL;
			break;
	}

	atakmap::commoncommo::CommoResult commoResult;
	atakmap::commoncommo::NetInterface* interface = commo->addStreamingInterface(protocol,
																					TCHAR_TO_UTF8(*Host), Port,
																					messageTypes.GetData(), messageTypes.Num(),
																					certContent.GetData(), certContent.Num(),
																					caCertContent.GetData(), caCertContent.Num(),
																					TCHAR_TO_UTF8(*ClientCertificatePassword), TCHAR_TO_UTF8(*CertificateAuthorityPassword),
																					TCHAR_TO_UTF8(*Username), TCHAR_TO_UTF8(*Password),
																					&commoResult);

	if (interface != nullptr)
	{
		Interface = interface;
	}

	bConnecting = false;
}

atakmap::commoncommo::Commo* UVH_COTConnectionInfo::GetCommo() const
{
	atakmap::commoncommo::Commo* commo = nullptr;

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		commo = cotManager->GetCommo();
	}

	return commo;
}

FString UVH_COTConnectionInfo::GetAuthorizationHeaderValue() const
{
	FString value = FString::Printf(TEXT("%s:%s"), *Username, *Password);

	return TEXT("Basic ") + FBase64::Encode(value);
}

void UVH_COTConnectionInfo::CreatePEMs() const
{
	FString openSSLPath = FPaths::Combine(FPaths::RootDir(), TEXT("Tools"), TEXT("openssl.exe"));
	FString args = TEXT("");

	if (!ClientCertificateName.IsEmpty())
	{
		if (!FPaths::FileExists(RootDirectory / TEXT("key.pem")))
		{
			args = FString::Printf(TEXT("pkcs12 -in %s -out %s/key.pem -passin pass:%s -nodes -nocerts"), *(RootDirectory / ClientCertificateName), *RootDirectory, *ClientCertificatePassword);
			FProcHandle procHandle = FPlatformProcess::CreateProc(*openSSLPath, *args, true, true, true, nullptr, 0, nullptr, nullptr);
			FPlatformProcess::WaitForProc(procHandle);
		}

		if (!FPaths::FileExists(RootDirectory / TEXT("cert.pem")))
		{
			args = FString::Printf(TEXT("pkcs12 -in %s -out %s/cert.pem -passin pass:%s -clcerts -nokeys"), *(RootDirectory / ClientCertificateName), *RootDirectory, *ClientCertificatePassword);
			FProcHandle procHandle = FPlatformProcess::CreateProc(*openSSLPath, *args, true, true, true, nullptr, 0, nullptr, nullptr);
			FPlatformProcess::WaitForProc(procHandle);
		}
	}

	if (!CertificateAuthorityName.IsEmpty())
	{
		if (!FPaths::FileExists(RootDirectory / TEXT("caCert.pem")))
		{
			args = FString::Printf(TEXT("pkcs12 -in %s -out %s/caCert.pem -passin pass:%s -cacerts -nokeys"), *(RootDirectory / CertificateAuthorityName), *RootDirectory, *CertificateAuthorityPassword);
			FProcHandle procHandle = FPlatformProcess::CreateProc(*openSSLPath, *args, true, true, true, nullptr, 0, nullptr, nullptr);
			FPlatformProcess::WaitForProc(procHandle);
		}
	}
}