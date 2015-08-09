#ifndef IGENERATORREGISTRY_H
#define IGENERATORREGISTRY_H

#include <memory>
#include "IGenerator.h"
#include "StringView.h"

class IGeneratorRegistry {
public:
    virtual ~IGeneratorRegistry() {}

    virtual std::shared_ptr<IGenerator> getGenerator(const StringView &name) = 0;
};

#endif
