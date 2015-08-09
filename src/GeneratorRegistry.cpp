#include "GeneratorRegistry.h"

void GeneratorRegistry::addGenerator(const StringView &name,
                                     std::shared_ptr<IGenerator> generator)
{
    key.assign(name.begin(), name.end());
    generators.emplace(key, generator);
}

std::shared_ptr<IGenerator> GeneratorRegistry::getGenerator(const StringView &name)
{
    key.assign(name.begin(), name.end());
    auto i = generators.find(key);
    if (i == generators.end()) {
        return std::shared_ptr<IGenerator>();
    }
    return i->second;
}
