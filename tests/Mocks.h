#ifndef MOCKS_H
#define MOCKS_H

#include <gmock/gmock.h>
#include "IGenerator.h"
#include "IGeneratorRegistry.h"

namespace mocks {

class Generator : public IGenerator {
public:
    MOCK_METHOD1(generateTo, void (std::ostream &));
};

class GeneratorRegistry : public IGeneratorRegistry {
public:
    MOCK_METHOD1(getGenerator, std::shared_ptr<IGenerator> (const StringView &));
};

}

#endif
