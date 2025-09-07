// Required Includes
#include "Game_MeshComponent_CesiumIon.h"
#include "Game.h"

// Engine Includes
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Async/Async.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonSerializerMacros.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_GlobeMathStatics.h"
#include "VH_FileIOStatics.h"
#include "VH_GlobeReferenceActor.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "VH_GlobeCoordConverter.h"

// Game Includes
#include "Game_TileManager.h"
#include "Game_TileUtilities.h"
#include "Game_TileManager.h"
#include "Game_Statics.h"

#define ENGINE_API_CACHE ENGINE_API
#undef ENGINE_API

// todo ohg | copy/paste from math/Vector4.h | why is this needed?
#include <cmath>
#include "math/Point2.h"
#include "port/Platform.h"
#include "util/Error.h"
namespace TAK 
{
    namespace Engine
    {
        namespace Math 
        {
            template<class T>
            Point2<T> Vector2_add(const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                const T x = a.x + b.x;
                const T y = a.y + b.y;
                const T z = a.z + b.z;
                return Point2<T>(x, y, z);

            }
            template<class T>
            Util::TAKErr Vector2_add(Point2<T> *value, const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                if (!value)
                    return Util::TE_InvalidArg;
                *value = Vector2_add(a, b);
                return Util::TE_Ok;

            }
            template<class T>
            Point2<T> Vector2_subtract(const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                const T x = a.x - b.x;
                const T y = a.y - b.y;
                const T z = a.z - b.z;
                return Point2<T>(x, y, z);
            }
            template<class T>
            Util::TAKErr Vector2_subtract(Point2<T> *value, const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                if (!value)
                    return Util::TE_InvalidArg;
                *value = Vector2_subtract(a, b);
                return Util::TE_Ok;
            }
            template<class T>
            Point2<T> Vector2_multiply(const Point2<T> &src, const T v) NOTHROWS
            {
                const T x = src.x * v;
                const T y = src.y * v;
                const T z = src.z * v;
                return Point2<T>(x, y, z);
            }
            template<class T>
            Util::TAKErr Vector2_multiply(Point2<T> *value, const Point2<T> &src, const T v) NOTHROWS
            {
                if (!value)
                    return Util::TE_InvalidArg;
                *value = Vector2_multiply<T>(src, v);
                return Util::TE_Ok;
            }
            template<class T>
            Point2<T> Vector2_multiply(const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                const T x = a.x * b.x;
                const T y = a.y * b.y;
                const T z = a.z * b.z;
                return Point2<T>(x, y, z);
            }
            template<class T>
            Util::TAKErr Vector2_multiply(Point2<T> *value, const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                if (!value)
                    return Util::TE_InvalidArg;
                *value = Vector2_multiply<T>(a, b);
                return Util::TE_Ok;
            }
            template<class T>
            T Vector2_dot(const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                const Point2<T> product = Vector2_multiply<T>(a, b);
                return product.x + product.y + product.z;
            }
            template<class T>
            Util::TAKErr Vector2_dot(T *value, const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                if (!value)
                    return Util::TE_InvalidArg;
                *value = Vector2_dot(a, b);
                return Util::TE_Ok;
            }
            template<class T>
            double Vector2_length(const Point2<T> &src) NOTHROWS
            {
                return sqrt(src.x*src.x + src.y*src.y + src.z*src.z);
            }
            template<class T>
            Util::TAKErr Vector2_length(double *value, const Point2<T> &src) NOTHROWS
            {
                if (!value)
                    return Util::TE_InvalidArg;
                *value = Vector2_length(src);
                return Util::TE_Ok;
            }
            template<class T>
            Util::TAKErr Vector2_normalize(Point2<T> *value, const Point2<T> &src) NOTHROWS
            {
                Util::TAKErr code(Util::TE_Ok);

                double mag;
                code = Vector2_length<T>(&mag, src);
                TE_CHECKRETURN_CODE(code);

                if (!mag)
                    return Util::TE_Err;

                code = Vector2_multiply<T>(value, src, 1.0 / mag);
                TE_CHECKRETURN_CODE(code);

                return code;
            }
            template<class T>
            Point2<T> Vector2_normalize(const Point2<T>& src) NOTHROWS
            {
                return Vector2_multiply<T>(src, static_cast<T>(1.0 / Vector2_length(src)));
            }
            template<class T>
            Point2<T> Vector2_cross(const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                const double x = a.y*b.z - a.z*b.y;
                const double y = a.z*b.x - a.x*b.z;
                const double z = a.x*b.y - a.y*b.x;
                return Point2<T>(x, y, z);
            }
            template<class T>
            Util::TAKErr Vector2_cross(Point2<T> *value, const Point2<T> &a, const Point2<T> &b) NOTHROWS
            {
                if (!value)
                    return Util::TE_InvalidArg;
                *value = Vector2_cross(a, b);
                return Util::TE_Ok;
            }
            template<class T>
            bool Vector2_polygonContainsPoint(const Point2<T> &point, const Point2<T> *polygon, size_t polygonLen) NOTHROWS
            {
                size_t i, j;
                bool result = false;
                if (polygonLen <= 0)
                    return false;
                for (i = 0, j = polygonLen - 1; i < polygonLen; j = i++) {
                    if ((polygon[i].y > point.y) != (polygon[j].y > point.y)
                        &&
                        (point.x < (polygon[j].x - polygon[i].x)
                            * (point.y - polygon[i].y)
                            / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
                        result = !result;
                    }
                }
                return result;
            }


            template<class T>
            class Vector4
            {
            public:
                Vector4(T x, T y, T z);
                ~Vector4();
            public:
                void add(const Vector4<T> *v, Vector4<T> *result) const;
                void subtract(const Vector4<T> *v, Vector4<T> *result) const;
                void multiply(const T v, Vector4<T> *result) const;

                double dot(const Vector4<T> *v) const;
                void normalize(Vector4<T> *v) const; // XXX - const precludes use of 'this'?
                void cross(Vector4<T> *v, Vector4<T>* result) const;
                double length() const;
            public:
                T x;
                T y;
                T z;
            };

            template<class T>
            inline Vector4<T>::Vector4(T _x, T _y, T _z) :
                x(_x), y(_y), z(_z)
            {}

            template<class T>
            inline Vector4<T>::~Vector4()
            {}

            template<class T>
            inline void Vector4<T>::add(const Vector4<T> *v, Vector4<T> *result) const
            {
                result->x = x + v->x;
                result->y = y + v->y;
                result->z = z + v->z;
            }

            template<class T>
            inline void Vector4<T>::subtract(const Vector4<T> *v, Vector4<T> *result) const
            {
                result->x = x - v->x;
                result->y = y - v->y;
                result->z = z - v->z;
            }

            template<class T>
            inline void Vector4<T>::multiply(const T v, Vector4<T> *result) const
            {
                result->x = x * v;
                result->y = y * v;
                result->z = z * v;
            }

            template<class T>
            inline double Vector4<T>::dot(const Vector4<T> *v) const
            {
                return x*v->x + y*v->y + z*v->z;
            }

            template<class T>
            inline void Vector4<T>::normalize(Vector4<T> *v) const
            {
                const double length = sqrt((x*x) + (y*y) + (z*z));
                multiply(1.0 / length, v);
            }

            template<class T>
            inline double Vector4<T>::length() const
            {
                return sqrt(this->dot(this));
            }

            template<class T>
            inline void Vector4<T>::cross(Vector4<T> *v, Vector4<T>* result) const
            {
                result->x = this->y*v->z - this->z*v->y;
                result->y = this->z*v->x - this->x*v->z;
                result->z = this->x*v->y - this->y*v->x;
            }
        }
    }
}
// end copy from math/Vector4.h

#include "formats/quantizedmesh/impl/QMElevationSampler.h"
#include "formats/quantizedmesh/QMESourceLayer.h"
#include "formats/quantizedmesh/TileCoord.h"
#include "feature/GeometryFactory.h"
#include "elevation/ElevationManager.h"
#include "elevation/ElevationSourceManager.h"
#include "elevation/ElevationSource.h"
#include "port/STLVectorAdapter.h"
#include "port/STLListAdapter.h"
#include "raster/osm/OSMUtils.h"
#undef ENGINE_API
#define ENGINE_API ENGINE_API_CACHE
#undef ENGINE_API_CACHE

using namespace TAK::Engine::Formats::QuantizedMesh::Impl;
using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Util;
using namespace TAK::Engine;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MeshComponent_CesiumIon::UGame_MeshComponent_CesiumIon()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

void UGame_MeshComponent_CesiumIon::GetTileFromGeodetic(const FGeodeticCoord2D& coordinate, int32 zoomLevel, TPair<int32, int32>& tileNumber)
{
	double spacing = 180.f / (1 << zoomLevel);

	tileNumber.Key = FMath::FloorToInt32((coordinate.Longitude + 180) / spacing);
	tileNumber.Value = FMath::FloorToInt32((coordinate.Latitude + 90) / spacing);
}

bool UGame_MeshComponent_CesiumIon::GetHAE(const FGeodeticCoord2D& coordinate, double& hae)
{
	FString fullPathToFile;
	int32 zoomLevel = -1;

	for (int32 zoom = 22; zoom > 4; zoom--)
	{
		TPair<int32, int32> tile;
		GetTileFromGeodetic(coordinate, zoom, tile);

		fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), zoom, tile.Key, tile.Value);

		if (FPaths::FileExists(fullPathToFile))
		{
			zoomLevel = zoom;
			
			break;
		}
	}

	if (zoomLevel != -1)
	{
		std::shared_ptr<QMElevationSampler> sampler = std::make_shared<QMElevationSampler>(TCHAR_TO_ANSI(*fullPathToFile), TileCoord_getGSD(zoomLevel));

		TAKErr error = sampler->sample(&hae, coordinate.Latitude, coordinate.Longitude);
		if (error != TAKErr::TE_Ok)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_CesiumIon::GetHAE | error | returning false | %s | %d | %s"), *coordinate.ToString(), error, *fullPathToFile);

			return false;
		}

		return true;
	}

	// no terrain files could be found for this coordinate
	return false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MeshComponent_CesiumIon::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();

	if (GetComponentStatus() == EComponentStatus::Initialized)
	{
		SetComponentStatus(EComponentStatus::HelperThreadStarted);

		if (Vertices.Num() == 0)
		{
			FString accessToken = TEXT("");
			FString assetID = TEXT("");
			if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
			{
				accessToken = gameSettings->GetSettingString(FString::Printf(TEXT("cesium_heightmap.CesiumAccessToken")));

				assetID = gameSettings->GetSettingString(FString::Printf(TEXT("cesium_heightmap.CesiumAssetID")));
			}

			if (!accessToken.IsEmpty() && !assetID.IsEmpty())
			{
				FString requestURL = FString::Printf(TEXT("https://api.cesium.com/v1/assets/%s/endpoint"), *assetID);

				FHttpModule* http = &FHttpModule::Get();

				TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
				request->SetURL(requestURL);
				request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *accessToken));
				request->SetVerb(TEXT("GET"));

				// bind callback
				request->OnProcessRequestComplete().BindLambda([this, assetID](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
				{
					if (!response.IsValid() || response->GetResponseCode() != 200)
					{
						FPlatformMisc::LowLevelOutputDebugStringf(TEXT("invalid cesium credentials"));

						return;
					}

					FString responseString = response->GetContentAsString();
					
					TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*response->GetContentAsString());

					TSharedPtr<FJsonObject> jsonObject;
					if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
					{
						FString accessToken;
						FString url;

						if (jsonObject->TryGetStringField(TEXT("url"), url) && jsonObject->TryGetStringField(TEXT("accessToken"), accessToken))
						{
							MakeHttpRequests(assetID, accessToken, url);
						}
						else
						{
							const TSharedPtr<FJsonObject>* optionsObjectPtr = nullptr;
							if (jsonObject->TryGetObjectField(TEXT("options"), optionsObjectPtr))
							{
								TSharedPtr<FJsonObject> optionsObject = *optionsObjectPtr;
								if (optionsObject->TryGetStringField(TEXT("url"), url) && optionsObject->TryGetStringField(TEXT("accessToken"), accessToken))
								{
									MakeHttpRequests(assetID, accessToken, url);
								}
							}
						}
					}
				});

				request->ProcessRequest();
			}
		}
		else if (bDrawDistanceDirty)
		{
			// ApplyDrawDistance calls SetComponentStatus(HelperThreadFinished) when finished
			ApplyDrawDistance();
		}
		else
		{
			SetComponentStatus(EComponentStatus::HelperThreadFinished);
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MeshComponent_CesiumIon::MakeHttpRequests(const FString& assetID, const FString& accessToken, const FString& url)
{
	// determine tiles to pull
	GetTileFromGeodetic(GetNorthWestBound(), GetZoomLevel(), NorthWestTile);
	GetTileFromGeodetic(GetSouthEastBound(), GetZoomLevel(), SouthEastTile);

	UGame_TileManager* tileManager = UGame_TileManager::Get();

	// get all tiles' imagery data
	for (int32 y = FMath::Min<int32>(SouthEastTile.Value, NorthWestTile.Value); y <= FMath::Max<int32>(SouthEastTile.Value, NorthWestTile.Value); y++)
	{
		for (int32 x = FMath::Min<int32>(SouthEastTile.Key, NorthWestTile.Key); x <= FMath::Max<int32>(SouthEastTile.Key, NorthWestTile.Key); x++)
		{
			FString fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), GetZoomLevel(), x, y);
			
			TPair<int32, int32> tileNumber(x, y);
			IFileManager& fileManager = IFileManager::Get();
			if (!fileManager.FileExists(*fullPathToFile))
			{
				FString tileIdentifier = TileUtilities::GetTileIdentifier(tileNumber, GetZoomLevel(), TEXT("cesiumHeight"), TEXT("quantized-mesh"));
				
				FString requestURL = FString::Printf(TEXT("%s%d/%d/%d.terrain"), *url, GetZoomLevel(), tileNumber.Key, tileNumber.Value);
				
				FHttpModule* http = &FHttpModule::Get();

				TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();
				request->SetURL(requestURL);
				request->AppendToHeader(TEXT("authorization"), FString::Printf(TEXT("Bearer %s"), *accessToken));
				request->AppendToHeader(TEXT("Accept"), TEXT("application/vnd.quantized-mesh,application/octet-stream;q=0.9"));
				request->AppendToHeader(TEXT("email"), FString::Printf(TEXT("%d.%d.%d"), tileNumber.Key, tileNumber.Value, GetZoomLevel()));
				request->SetVerb(TEXT("GET"));

				tileManager->AddHTTPRequest(tileIdentifier, this, request);

				RequestsCounter.Increment();
			}
		}
	}

	// if everything already exists on disk, skip to reading data
	if (RequestsCounter.GetValue() == 0)
	{
		ReadDataFromAllTiles();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_MeshComponent_CesiumIon::GetHAE(const FGeodeticCoord2D& coordinate, double& hae, int32 zoomLevel)
{
	TPair<int32, int32> tile;
	GetTileFromGeodetic(coordinate, zoomLevel, tile);

	FString samplerID = FString::Printf(TEXT("%d|%d|%d"), zoomLevel, tile.Key, tile.Value);

	std::shared_ptr<QMElevationSampler> sampler;
	if (std::shared_ptr<QMElevationSampler>* samplerPtr = Samplers.Find(samplerID))
	{
		sampler = *samplerPtr;
	}
	else
	{
		FString fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), zoomLevel, tile.Key, tile.Value);

		sampler = std::make_shared<QMElevationSampler>(TCHAR_TO_ANSI(*fullPathToFile), TileCoord_getGSD(zoomLevel));
			
		Samplers.Add(samplerID, sampler);
	}

	TAKErr error = sampler->sample(&hae, coordinate.Latitude, coordinate.Longitude);
	if (error != TAKErr::TE_Ok)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_CesiumIon::GetHAE | error | returning false | %s | %d"), *coordinate.ToString(), error);

		return false;
	}
		
	return true;
}

void UGame_MeshComponent_CesiumIon::OnHTTPRequestComplete(const FString& tileIdentifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	Async(EAsyncExecution::ThreadPool, [this, request, response, bWasSuccessful]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		bool bValid = true;

		if (!response.IsValid())
		{
			FPlatformMisc::LowLevelOutputDebugStringf(TEXT("UGame_MeshComponent_CesiumIon::OnHTTPRequestComplete | invalid heightmap received"));

			bValid = false;
		}

		if (response->GetContentAsString().Contains(TEXT("NoSuchKey")))
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_MeshComponent_CesiumIon::OnHTTPRequestComplete | received NoSuchKey"));

			bValid = false;
		}

		if (bValid)
		{
			TArray<uint8> content = response->GetContent();
			FString type = response->GetContentType();

			FJsonSerializableArray headers;
			headers = response->GetAllHeaders();

			FJsonSerializableArray other;
			other = headers;

			FString tileID = request->GetHeader(TEXT("email"));

			TArray<FString> parsedID;
			tileID.ParseIntoArray(parsedID, TEXT("."), false);

			TPair<int32, int32> tileNumber;
			tileNumber.Key = FCString::Atoi(*parsedID[0]);
			tileNumber.Value = FCString::Atoi(*parsedID[1]);
			int32 zoomLevel = FCString::Atoi(*parsedID[2]);

			//TileUtilities::WriteTileToDisk(tileNumber, zoomLevel, TEXT("cesiumHeight"), TEXT("quantized-mesh"), content);
			
			FString fullPathToFile = FString::Printf(TEXT("%s/3DTiles/1/%d/%d/%d.terrain"), *UGame_Statics::GetVTAKCommonAppDataPath(), zoomLevel, tileNumber.Key, tileNumber.Value);
			FFileHelper::SaveArrayToFile(content, *fullPathToFile);
		}

		RequestsCounter.Decrement();

		ReadDataFromAllTiles();

		DestroyCounter.Decrement();
	});
}

void UGame_MeshComponent_CesiumIon::ReadDataFromAllTiles()
{
	if (RequestsCounter.GetValue() != 0)
	{
		return;
	}

	Async(EAsyncExecution::ThreadPool, [this]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();
		if (globeReference == nullptr)
		{
			DestroyCounter.Decrement();
			return;
		}

		float minHAE = MAX_FLT;
		float maxHAE = MIN_flt;

		FGeodeticCoord2D northWestBound = GetNorthWestBound();
		FGeodeticCoord2D southEastBound = GetSouthEastBound();
		double westEastMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWestBound, FGeodeticCoord2D(southEastBound.Longitude, northWestBound.Latitude));
		double northSouthMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWestBound, FGeodeticCoord2D(northWestBound.Longitude, southEastBound.Latitude));

		int32 zoomLevel = GetZoomLevel();

		// going with 256 'pixels' per terrain file
		double postSpacingMetersLongitude = UVH_GlobeMathStatics::PostDistanceMetersOfZoomLevel(zoomLevel) / 256.0;
		double postSpacingMetersLatitude = postSpacingMetersLongitude;

		double longitudeDivisor = westEastMeters / postSpacingMetersLongitude;
		double latitudeDivisor = northSouthMeters / postSpacingMetersLatitude;

		double longitudeIncrement = (southEastBound.Longitude - northWestBound.Longitude) / longitudeDivisor;
		double latitudeIncrement = (northWestBound.Latitude - southEastBound.Latitude) / latitudeDivisor;

		int32 totalLongitudePosts = 0;
		int32 totalLatitudePosts = 0;
		TArray<double> srcLatitude;
		TArray<double> srcLongitude;
		for (double latitude = northWestBound.Latitude; latitude >= southEastBound.Latitude; latitude -= latitudeIncrement)
		{
			for (double longitude = northWestBound.Longitude; longitude <= southEastBound.Longitude; longitude += longitudeIncrement)
			{
				srcLatitude.Add(latitude);
				srcLongitude.Add(longitude);
									
				if (latitude == northWestBound.Latitude)
				{
					totalLongitudePosts++;
				}

				if (longitude == northWestBound.Longitude)
				{
					totalLatitudePosts++;
				}
			}
		}

		TArray<double> haeValues;
		haeValues.AddZeroed(totalLongitudePosts * totalLatitudePosts);
		
		for (int32 i = 0; i < haeValues.Num(); i++)
		{
			FGeodeticCoord2D coordinate(srcLongitude[i], srcLatitude[i]);

			GetHAE(coordinate, haeValues[i], zoomLevel);
		}

		// determine xStepUU and yStepUU
		FGeodeticCoord2D swCoord(northWestBound.Longitude, southEastBound.Latitude);

		TArray<FVector> vertices;
		TArray<FVector2D> uvs;

		HAEBounds = FVector2D(9999999, -9999999);

		// vertex for each post
		for (int32 y = 0; y < totalLatitudePosts; y++)
		{
			for (int32 x = 0; x < totalLongitudePosts; x++)
			{
				int32 index = (y * totalLongitudePosts) + x;

				double hae = haeValues[index];

				// northwest -> southeast
				FGeodeticCoord3D vertexCoordinate;
				vertexCoordinate.Longitude = FMath::Lerp<double>(swCoord.Longitude, southEastBound.Longitude, x / (totalLongitudePosts - 1.f));
				vertexCoordinate.Latitude = FMath::Lerp<double>(northWestBound.Latitude, swCoord.Latitude, y / (totalLatitudePosts - 1.f));
				vertexCoordinate.Altitude = hae;

				vertices.Add(globeReference->GeodeticToWorldDouble(vertexCoordinate));

				HAEBounds.X = FMath::Min<double>(HAEBounds.X, hae);
				HAEBounds.Y = FMath::Max<double>(HAEBounds.Y, hae);

				float uvX = (float)x / (float)(totalLongitudePosts - 1);
				float uvY = (float)y / (float)(totalLatitudePosts - 1);
				uvs.Add(FVector2D(uvX, uvY));
			}
		}

		// generate triangles
		TArray<int32> triangles;
		for (int32 y = 0; y < totalLatitudePosts; y++)
		{
			for (int32 x = 0; x < totalLongitudePosts - 1; x++)
			{
				if (y > 0)
				{
					int32 start = y * totalLongitudePosts;

					int32 bottomLeft = start + x;
					int32 bottomRight = start + x + 1;
					int32 topRight = start - totalLongitudePosts + x + 1;
					int32 topLeft = start - totalLongitudePosts + x;

					//
					//    . .
					//    .
					//
					triangles.Add(topRight);
					triangles.Add(topLeft);
					triangles.Add(bottomLeft);

					//
					//      .
					//    . .
					//
					triangles.Add(bottomLeft);
					triangles.Add(bottomRight);
					triangles.Add(topRight);
				}
			}
		}

		{
			FScopeLock scopeLock(UVsCritSection);
			UVs.Empty();
			UVs.Append(uvs);
		}

		{
			FScopeLock scopeLock(VerticesCritSection);
			Vertices.Empty();
			Vertices.Append(vertices);
		}

		{
			FScopeLock scopeLock(TrianglesCritSection);
			Triangles.Empty();
			Triangles.Append(triangles);
		}
		
		ApplyDrawDistance();

		DestroyCounter.Decrement();
	});
}

bool UGame_MeshComponent_CesiumIon::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

FGeodeticCoord2D UGame_MeshComponent_CesiumIon::GetNorthwestCoordinate(const TPair<int32, int32>& tileNumber, int32 zoomLevel) const
{
	FGeodeticCoord2D northWestCorner;
	int32 numTilesY = 1 << zoomLevel;

	northWestCorner.Longitude = (tileNumber.Key / (2.f * (float)numTilesY) * 360.0) - 180.0;
	northWestCorner.Latitude = ((tileNumber.Value + 1) / (float)numTilesY * 180.0) - 90.0;

	return northWestCorner;
}