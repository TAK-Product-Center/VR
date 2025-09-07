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
                return PfpsMapTypeFrame::getMapType(frame);
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
