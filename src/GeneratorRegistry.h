#ifndef GENERATORREGISTRY_H
#define GENERATORREGISTRY_H

#include <unordered_map>
#include <vector>
#include "IGeneratorRegistry.h"

class GeneratorRegistry : public IGeneratorRegistry {
public:
    void addGenerator(const StringView &name,
                      std::shared_ptr<IGenerator> generator);
    std::shared_ptr<IGenerator> getGenerator(const StringView &name) override;

private:
    std::unordered_map<std::string, std::shared_ptr<IGenerator>> generators;
    std::string key;
};

#endif
