#ifndef ATAK_MDBACCESSDATABASE_H
#define ATAK_MDBACCESSDATABASE_H

#include "db/DatabaseProvider.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace MsAccess {

                class ENGINE_API MDBAccessDatabaseProvider : public TAK::Engine::DB::DatabaseProvider {
                public :
                    MDBAccessDatabaseProvider() NOTHROWS;
                public : // DatabaseProvider
                    virtual Util::TAKErr create(TAK::Engine::DB::DatabasePtr &result, const DB::DatabaseInformation &information) NOTHROWS override;
                    virtual Util::TAKErr getType(const char **value) NOTHROWS override;
                };

            }  // namespace MsAccess
        }  // namespace Formats
    }  // namespace Engine
}  // namespace TAK


#endif //ATAK_MDBACCESSDATABASE_H
