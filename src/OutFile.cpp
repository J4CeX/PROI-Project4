#include "OutFile.hpp"

OutFile::OutFile(const std::string& fname) {
    this->name = fname;
    this->ofile.open(fname);
    if (this->ofile.good()) {
        this->isGood = true;
    }
    else {
        this->isGood = false;
    }
}

void OutFile::saveFile(const Image& image) const {
    if (this->isGood) {

    }
}

OutFile::~OutFile() {
    if (this->ofile.is_open()) {
        this->ofile.close();
    }
}