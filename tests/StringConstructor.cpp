#include <gmock/gmock.h>
#include "StringConstructor.h"

using namespace testing;

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

TEST(StringConstructor, default)
{
    mocks::GeneratorRegistry registry;
    EXPECT_CALL(registry, getGenerator(_)).
        Times(0);
    StringConstructor sc("", registry);
}

TEST(StringConstructor, template_1)
{
    mocks::GeneratorRegistry registry;
    EXPECT_CALL(registry, getGenerator(StringView("ABC")));
    EXPECT_CALL(registry, getGenerator(StringView("DEF")));
    StringConstructor sc("${ABC}${DEF}", registry);
}

TEST(StringConstructor, template_2)
{
    mocks::GeneratorRegistry registry;
    EXPECT_CALL(registry, getGenerator(StringView("ABC")));
    EXPECT_CALL(registry, getGenerator(StringView("DEF")));
    StringConstructor sc("...${ABC}...${DEF}...", registry);
}

TEST(StringConstructor, invalid_template)
{
    mocks::GeneratorRegistry registry;
    EXPECT_CALL(registry, getGenerator(_)).
        Times(0);
    StringConstructor sc("${ABC", registry);
}
