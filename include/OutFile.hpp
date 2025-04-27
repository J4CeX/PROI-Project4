#include <fstream>
#include "Image.hpp"

namespace SVG {
    class OutFile {
    private:
        std::ofstream ofile;
        std::string name;
        bool isGood;

    public:
        OutFile(const std::string& fname);
        void saveFile(const Image& image);
        ~OutFile();
    };
}