#include "Element.hpp"
#include <fstream>

namespace Element {
    class Text: public Element {
        private:
            int fontSize;
            std::string textAnchor, content;
        public:
            Text(const std::string& content, const int& x=0, const int& y=0,
                const int& fontSize=16, const std::string& textAnchor="start",
                const std::string& fill="none", const std::string& stroke="none")
                : Element(x, y, NULL, NULL, fill, stroke),
                content(content) ,fontSize(fontSize), textAnchor(textAnchor) {}
            int getFontSize() const { return fontSize; }
            std::string getTextAnchor() const { return textAnchor; }
            std::string getContent() const { return content; }
            friend std::ofstream& operator<<(std::ofstream& ofile, const Text& text);
    };
    std::ofstream& operator<<(std::ofstream& ofile, const Text& text);
}