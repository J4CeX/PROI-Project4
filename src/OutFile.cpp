#include "OutFile.hpp"

namespace SVG {
    OutFile::OutFile(const std::string& fname) {
        name = fname;
        ofile.open(fname);
        if (ofile.good()) {
            isGood = true;
        }
        else {
            isGood = false;
        }
    }

    void OutFile::saveFile(const Image& image) {
        if (isGood) {
            ofile << image;
        }
    }

    OutFile::~OutFile() {
        if (ofile.is_open()) {
            ofile.close();
        }
    }
}