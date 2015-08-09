#ifndef STRINGCONSTRUCTOR_H
#define STRINGCONSTRUCTOR_H

#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include "IGeneratorRegistry.h"
#include "IGenerator.h"
#include "StringView.h"

class StringConstructor {
public:
    StringConstructor(const StringView &template_,
                      IGeneratorRegistry &generators);

    void constructTo(std::ostream &);

private:
    std::vector<std::shared_ptr<IGenerator>> program;
};

#endif
