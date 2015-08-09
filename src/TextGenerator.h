#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H

#include <string>
#include "IGenerator.h"
#include "StringView.h"

class TextGenerator : public IGenerator {
public:
    explicit TextGenerator(const StringView &text);

    void generateTo(std::ostream &) override;

private:
    std::string text;
};

#endif
