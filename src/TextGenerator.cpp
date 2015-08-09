#include "TextGenerator.h"

TextGenerator::TextGenerator(const StringView &_text) :
    text(_text.begin(), _text.end())
{
}

void TextGenerator::generateTo(std::ostream &stream)
{
    stream << text;
}
