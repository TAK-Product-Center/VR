#include "PfpsUtils.h"

#include "PfpsMapType.h"
#include "PfpsMapTypeFrame.h"
#include "util/IO.h"
#include "math/Utils.h"
#include "math/Point.h"
#include "gdal_priv.h"
#include "raster/gdal/GdalDatasetProjection.h"
#include <string>
#include <set>
#include <map>


namespace {
    using namespace atakmap::raster::pfps;
    using namespace atakmap::util;
    using namespace atakmap::core;

    const PfpsMapType *RPF_MAP_TYPES[] = {
        new PfpsMapType("GN", 5000000.0, PfpsMapType::SCALE_UNIT_SCALE, "cgnc", "CADRG", "GNC", "Raster"),
        new PfpsMapType("JN", 2000000.0, PfpsMapType::SCALE_UNIT_SCALE, "cjnc", "CADRG", "JNC", "Raster"),
        new PfpsMapType("ON", 1000000.0, PfpsMapType::SCALE_UNIT_SCALE, "conc", "CADRG", "ONC", "Raster"),
        new PfpsMapType("LF", 500000.0, PfpsMapType::SCALE_UNIT_SCALE, "clfc", "CADRG", "LFC Day", "Raster"),
        new PfpsMapType("TP", 500000.0, PfpsMapType::SCALE_UNIT_SCALE, "ctpc", "CADRG", "TPC", "Raster"),
        new PfpsMapType("TF", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "ctfc", "CADRG", "TFC", "Raster"),
        new PfpsMapType("JA", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "cjga", "CADRG", "JOG", "Raster"),
        new PfpsMapType("TC", 100000.0, PfpsMapType::SCALE_UNIT_SCALE, "ctlm100", "CADRG", "TLM", "Raster"),
        new PfpsMapType("TL", 50000.0, PfpsMapType::SCALE_UNIT_SCALE, "ctlm50", "CADRG", "TLM", "Raster"),
        new PfpsMapType("I1", 10.0, PfpsMapType::SCALE_UNIT_METER, "cib10", "CIB", nullptr, "Raster"),
        new PfpsMapType("I2", 5.0, PfpsMapType::SCALE_UNIT_METER, "cib5", "CIB", nullptr, "Raster"),
        new PfpsMapType("I4", 1.0, PfpsMapType::SCALE_UNIT_METER, "cib1", "CIB", nullptr, "Raster"),
        new PfpsMapType("CA", 15000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg15", "CADRG", "CG", "Raster"),
        new PfpsMapType("MM", 50000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm50", "CADRG", "MM", "Raster"),
        new PfpsMapType("MM", 100000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm100", "CADRG", "MM", "Raster"),
        new PfpsMapType("MM", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm250", "CADRG", "MM", "Raster"),
        new PfpsMapType("MM", 25000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm25", "CADRG", "MM", "Raster"),
        new PfpsMapType("CT", 36000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg36", "CADRG", "CG", "Raster"),
        new PfpsMapType("CS", 35000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg35", "CADRG", "CG", "Raster"),
        new PfpsMapType("CR", 26000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg26", "CADRG", "CG", "Raster"),
        new PfpsMapType("CQ", 25000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg25", "CADRG", "CG", "Raster"),
        new PfpsMapType("CP", 23000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg23", "CADRG", "CG", "Raster"),
        new PfpsMapType("CN", 22000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg22", "CADRG", "CG", "Raster"),
        new PfpsMapType("CL", 21120.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg21120", "CADRG", "CG", "Raster"),
        new PfpsMapType("CK", 21000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg21", "CADRG", "CG", "Raster"),
        new PfpsMapType("CJ", 20000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg20", "CADRG", "CG", "Raster"),
        new PfpsMapType("CH", 18000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg18", "CADRG", "CG", "Raster"),
        new PfpsMapType("CF", 17500.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg17500", "CADRG", "CG", "Raster"),
        new PfpsMapType("CE", 17000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg17", "CADRG", "CG", "Raster"),
        new PfpsMapType("CD", 16666.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg16666", "CADRG", "CG", "Raster"),
        new PfpsMapType("CC", 16000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg16", "CADRG", "CG", "Raster"),
        new PfpsMapType("CB", 15500.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg15500", "CADRG", "CG", "Raster"),
        new PfpsMapType("C9", 14700.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg14700", "CADRG", "CG", "Raster"),
        new PfpsMapType("C8", 14000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg14", "CADRG", "CG", "Raster"),
        new PfpsMapType("C7", 12800.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg12800", "CADRG", "CG", "Raster"),
        new PfpsMapType("C6", 12500.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg12500", "CADRG", "CG", "Raster"),
        new PfpsMapType("C5", 12000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg12", "CADRG", "CG", "Raster"),
        new PfpsMapType("C4", 11800.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg11800", "CADRG", "CG", "Raster"),
        new PfpsMapType("C3", 11000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg11", "CADRG", "CG", "Raster"),
        new PfpsMapType("C2", 10560.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg10560", "CADRG", "CG", "Raster"),
        new PfpsMapType("C1", 10000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg10", "CADRG", "CG", "Raster"),
        new PfpsMapType("MM", 200000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm200", "CADRG", "MM", "Raster"),
        new PfpsMapType("MM", 24000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm24", "CADRG", "MM", "Raster"),
        new PfpsMapType("TN", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "ctfn", "CADRG", "TFC Night", "Raster"),
        new PfpsMapType("LN", 500000.0, PfpsMapType::SCALE_UNIT_SCALE, "clfn", "CADRG", "LFC Night", "Raster"),
        new PfpsMapType("SA", 500000.0, PfpsMapType::SCALE_UNIT_SCALE, "usa-sec", "CADRG", "USA Sectional", "Raster"),
        new PfpsMapType("VT", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "vfr", "CADRG", "VFR Terminal Area Chart", "Raster"),
        new PfpsMapType("JO", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "opg", "CADRG", "Operational Planning Graph", "Raster"),
        new PfpsMapType("JG", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "jogg", "CADRG", "JOG-G", "Raster"),
        new PfpsMapType("JR", 250000.0, PfpsMapType::SCALE_UNIT_SCALE, "jogr", "CADRG", "JOG-R", "Raster"),
        new PfpsMapType("CG", 1000000.0, PfpsMapType::SCALE_UNIT_SCALE, "ccg1M", "CADRG", "CG", "Raster"),
        new PfpsMapType("VH", 125000.0, PfpsMapType::SCALE_UNIT_SCALE, "chrc125", "CADRG", "Helicopter Route Chart", "Raster"),
        new PfpsMapType("OW", 1000000.0, PfpsMapType::SCALE_UNIT_SCALE, "chfc1M", "CADRG", "High Flying Chart", "Raster"),
        new PfpsMapType("MI", 50000.0, PfpsMapType::SCALE_UNIT_SCALE, "mim50", "CADRG", "Military Installation Map", "Raster"),
        new PfpsMapType("OH", 1000000.0, PfpsMapType::SCALE_UNIT_SCALE, "cvfr1M", "CADRG", "VFR Helicopter Route Chart", "Raster"),
        new PfpsMapType("UL", 50000.0, PfpsMapType::SCALE_UNIT_SCALE, "tlm50_o", "CADRG", "TLM - Other", "Raster"),
        new PfpsMapType("TT", 25000.0, PfpsMapType::SCALE_UNIT_SCALE, "tlm25", "CADRG", "TLM", "Raster"),
        new PfpsMapType("TQ", 24000.0, PfpsMapType::SCALE_UNIT_SCALE, "tlm24", "CADRG", "TLM", "Raster"),
        new PfpsMapType("TR", 200000.0, PfpsMapType::SCALE_UNIT_SCALE, "tlm200", "CADRG", "TLM", "Raster"),
        new PfpsMapType("MM", 145826.0, PfpsMapType::SCALE_UNIT_SCALE, "mm145", "CADRG", "MM", "Raster"),
        new PfpsMapType("MM", 500000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm500", "CADRG", "MM", "Raster"),
        new PfpsMapType("MM", 1000000.0, PfpsMapType::SCALE_UNIT_SCALE, "mm1m", "CADRG", "MM", "Raster"),
        new PfpsMapType("CM", 10000.0, PfpsMapType::SCALE_UNIT_SCALE, "cc10", "CADRG", "Combat Chart", "Raster"),
        new PfpsMapType("CM", 25000.0, PfpsMapType::SCALE_UNIT_SCALE, "cc25", "CADRG", "Combat Chart", "Raster"),
        new PfpsMapType("CM", 50000.0, PfpsMapType::SCALE_UNIT_SCALE, "cc50", "CADRG", "Combat Chart", "Raster"),
        new PfpsMapType("CM", 100000.0, PfpsMapType::SCALE_UNIT_SCALE, "cc100", "CADRG", "Combat Chart", "Raster"),
        new PfpsMapType("I3", 2.0, PfpsMapType::SCALE_UNIT_METER, "cib2", "CIB", nullptr, "Raster"),
        new PfpsMapType("I5", 0.5, PfpsMapType::SCALE_UNIT_METER, "cib05", "CIB", nullptr, "Raster"),
        nullptr
    };

    std::map<std::string, const PfpsMapType *> createRpfFileExtensions()
    {
        std::map<std::string, const PfpsMapType *> ret;
        const PfpsMapType **mta = RPF_MAP_TYPES;
        while (*mta) {
            const PfpsMapType *mt = *mta;
            ret[mt->folderName] = mt;
            mta++;
        }
        return ret;
    }


    const std::map<std::string, const PfpsMapType *> RPF_FILE_EXTENSIONS(createRpfFileExtensions());

    int getRpfFrameNumberLen(const PfpsMapType *type) {
        int frameNumberLen = 6;
        const char CIB[] = "cib";
        for (int i = 0; i < 3; ++i) {
            if (type->folderName[i] != CIB[i]) {
                frameNumberLen = 5;
                break;
            }
        }
        return frameNumberLen;
    }



    struct RpfHeaderSection {
        /** true for LE, false for BE */
        const bool little_big_endian_indicator;
        const int header_section_length;
        const std::string file_name;
        const int new_replacement_update_indicator;
        const std::string governing_specification_number;
        const std::string governing_specification_date;
        const std::string security_classification;
        const std::string security_country_international_code;
        const std::string security_release_marking;
        const int location_section_location;

    private:
        RpfHeaderSection(bool little_big_endian_indicator,
                                 int header_section_length,
                                 std::string file_name,
                                 int new_replacement_update_indicator,
                                 std::string governing_specification_number,
                                 std::string governing_specification_date,
                                 std::string security_classification,
                                 std::string security_country_international_code,
                                 std::string security_release_marking,
                                 int location_section_location) :
                                 little_big_endian_indicator(little_big_endian_indicator),
                                 header_section_length(header_section_length),
                                 file_name(file_name),
                                 new_replacement_update_indicator(new_replacement_update_indicator),
                                 governing_specification_number(governing_specification_number),
                                 governing_specification_date(governing_specification_date),
                                 security_classification(security_classification),
                                 security_country_international_code(security_country_international_code),
                                 security_release_marking(security_release_marking),
                                 location_section_location(location_section_location)
        {
        }

    public:
        static RpfHeaderSection parse(DataInput *input) {
            bool lbei = (input->readByte() & 0xFF) == 0xFF;
            if (lbei)
                input->setSourceEndian(LITTLE_ENDIAN);
            else
                input->setSourceEndian(BIG_ENDIAN);
            int hsl = input->readShort() & 0xFFFF;
            std::string fn = input->readString(12);
            int nrui = input->readByte() & 0xFF;
            std::string gsn = input->readString(15);
            std::string gsd = input->readString(8);
            std::string sc = input->readString(1);
            std::string scic = input->readString(2);
            std::string srm = input->readString(2);
            int lsl = input->readInt();

            return RpfHeaderSection(lbei, hsl, fn, nrui, gsn, gsd, sc, scic, srm, lsl);
        }
    };


    const size_t NITF_IDENT_SIZE = 9;

    bool quickFrameCoverageNitf20(FileInput *input, GeoPoint *coverage) {
        input->skip(360 - NITF_IDENT_SIZE);

        try {
            int numi = input->readAsciiInt(3);
            input->skip(numi * (6 + 10));
            int nums = input->readAsciiInt(3);
            input->skip(nums * (4 + 6));
            int numx = input->readAsciiInt(3);
            input->skip(numx * 0);
            int numt = input->readAsciiInt(3);
            input->skip(numt * (4 + 5));
            int numdes = input->readAsciiInt(3);
            input->skip(numdes * (4 + 9));
            int numres = input->readAsciiInt(3);
            input->skip(numres * (4 + 7));
            int udhdl = input->readAsciiInt(5);
            if (udhdl == 0)
                return false;

            int udhofl = input->readAsciiInt(3);
            if (udhofl != 0)
                return false;

            while (true) {
                std::string id = input->readString(6);
                if (id.compare("RPFHDR") == 0)
                    break;
                int len = input->readAsciiInt(5);
                input->skip(len);
            }

            // TRE length
            input->skip(5);

            RpfHeaderSection header_section = RpfHeaderSection::parse(input);

            input->seek(header_section.location_section_location);

            input->skip(2);

            int component_location_table_offset = input->readInt();
            int number_of_component_location_records = input->readShort() & 0xFFFF;

            input->seek(header_section.location_section_location + component_location_table_offset);

            int component_location = -1;
            for (int i = 0; i < number_of_component_location_records; i++) {
                if ((input->readShort() & 0xFFFF) == 130) {
                    input->skip(4);
                    component_location = input->readInt();
                } else {
                    input->skip(8);
                }
            }

            if (component_location < 0)
                return false;

            input->seek(component_location);

            // north west
            double d1 = input->readDouble();
            double d2 = input->readDouble();
            coverage[0].set(d1, d2);
            // south west
            d1 = input->readDouble();
            d2 = input->readDouble();
            coverage[3].set(d1, d2);
            // north east
            d1 = input->readDouble();
            d2 = input->readDouble();
            coverage[1].set(d1, d2);
            // south east
            d1 = input->readDouble();
            d2 = input->readDouble();
            coverage[2].set(d1, d2);

            // check for IDL crossing
            if (coverage[0].longitude > coverage[1].longitude) {
                coverage[1].set(coverage[1].latitude, 360.0 + coverage[1].longitude);
                coverage[2].set(coverage[2].latitude, 360.0 + coverage[2].longitude);
            }
        } catch (std::out_of_range &) {
            return false;
        }

        return true;
    }

    bool quickFrameCoverageNitf21(DataInput *input, GeoPoint *coverage) {
        return false;
    }


    bool quickFrameCoverage(const char *f, GeoPoint *coverage) {
        FileInput *input = nullptr;
        bool ret = false;
        try {
#if 0
            if (f instanceof ZipVirtualFile)
                inputStream = ((ZipVirtualFile)f).openStream();
            else
#endif
            {
                input = new FileInput();
                input->open(f);
            }

            std::string s = input->readString(NITF_IDENT_SIZE);
            if (s.compare("NITF02.10") == 0)
                ret = quickFrameCoverageNitf21(input, coverage);
            else if (s.compare("NITF02.00") == 0)
                ret = quickFrameCoverageNitf20(input, coverage);

        } catch (IO_Error &) {
        }

        if (input != nullptr) {
            input->close();
            delete input;
        }
        return ret;

    }



}

namespace atakmap {
    namespace raster {
        namespace pfps {


            const PfpsMapType *PfpsUtils::getMapType(const char *frame)
            {
                size_t n = strlen(frame);
                if (n != 12)
                    return nullptr;
                if (frame[8] != '.')
                    return nullptr;
                char c;
                for (int i = 0; i < 8; i++) {
                    c = frame[i];
                    if (c >= '0' && c <= '9')
                        continue;
                    c |= 32;
                    if (c < 'a' || c > 'z' || c == 'i' || c == 'o')
                        return nullptr;
                }
                char ext[3];
                ext[0] = frame[9];
                ext[1] = frame[10];
                ext[2] = '\0';
                return RPF_FILE_EXTENSIONS.at(ext);
            }

            /**
            * Derived from MIL-C-89041 sec 3.5.1
            */
            double PfpsUtils::cadrgScaleToCibResolution(double scale)
            {
                return (150.0 * 1e-6) / scale;
            }

            int PfpsUtils::getRpfZone(const char *frameFileName)
            {
                return base34Decode(frameFileName[11]);
            }


            int PfpsUtils::getRpfFrameVersion(const PfpsMapType *type, const char *frameFileName)
            {
                int frameNumberLen = getRpfFrameNumberLen(type);
                return base34Decode(frameFileName + frameNumberLen, 8 - frameNumberLen);
            }

            int PfpsUtils::getRpfFrameNumber(const PfpsMapType *type, const char *frameFileName)
            {
                int frameNumberLen = getRpfFrameNumberLen(type);
                return base34Decode(frameFileName, frameNumberLen);
            }

            int PfpsUtils::base34Decode(const char c)
            {
                if (c >= '0' && c <= '9') {
                    return (int)(c - '0');
                } else if (c >= 'A' && c <= 'z') {
                    char cc = c & ~32;
                    if (cc < 'I') {
                        return (int)(cc - 'A') + 10;
                    } else if (cc > 'I' && cc < 'O') {
                        return (int)(c - 'A') + 9;
                    } else if (cc > 'O') {
                        return (int)(cc - 'A') + 8;
                    }
                }

                return INT_MIN;
            }

            int PfpsUtils::base34Decode(const char *s)
            {
                int r = 0;
                while (*s != '\0') {
                    r = (r * 34) + base34Decode(*s);
                    if (r < 0)
                        break;
                    s++;
                }
                return r;
            }


            int PfpsUtils::base34Decode(const char *s, int len)
            {
                int r = 0;
                for (int i = 0; i < len; i++) {
                    r = (r * 34) + base34Decode(s[i]);
                    if (r < 0)
                        break;
                }
                return r;

            }

        }
    }
}
