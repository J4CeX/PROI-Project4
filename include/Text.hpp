#pragma once
#include "Element.hpp"

namespace SVG {
    class Text: public Element {
        private:
            int fontSize;
            std::string textAnchor, content;
        public:
            Text(const std::string& content, const int& x=0, const int& y=0,
                const int& fontSize=16, const std::string& textAnchor="start",
                const std::string& fill="none", const std::string& stroke="none")
                : Element(x, y, 0, 0, fill, stroke),
                content(content) ,fontSize(fontSize), textAnchor(textAnchor) {}
            int getFontSize() const { return fontSize; }
            std::string getTextAnchor() const { return textAnchor; }
            std::string getContent() const { return content; }
            void setFontSize(const int& newFontSize) { fontSize = newFontSize; }
            void setTextAnchor(const std::string& newTextAnchor) { textAnchor = newTextAnchor; }
            void setContent(const std::string& newContent) { content = newContent; }
            std::string print() const override;
            void edit() override;
            std::unique_ptr<Element> clone() const override { return std::make_unique<Text>(*this); }
            bool operator==(const Element& secElement) const override;
            bool operator!=(const Element& secElement) const override { return !(*this == secElement ); }
    };
}