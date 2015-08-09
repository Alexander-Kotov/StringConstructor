#include <gmock/gmock.h>
#include "StringConstructor.h"
#include "Mocks.h"

using namespace testing;

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

TEST(StringConstructor, template_3)
{
    mocks::GeneratorRegistry registry;
    EXPECT_CALL(registry, getGenerator(_)).
        Times(0);

    StringConstructor sc("...", registry);
}

TEST(StringConstructor, not_template)
{
    mocks::GeneratorRegistry registry;
    EXPECT_CALL(registry, getGenerator(_)).
        Times(0);

    StringConstructor sc("${ABC", registry);
}

TEST(StringConstructor, construct)
{
    auto printXyz = [](std::ostream &s) {
        s << "XYZ";
    };

    auto generator = std::make_shared<mocks::Generator>();
    EXPECT_CALL(*generator, generateTo(_)).
        WillRepeatedly(Invoke(printXyz));

    mocks::GeneratorRegistry registry;
    EXPECT_CALL(registry, getGenerator(StringView("ABC"))).
        WillRepeatedly(Return(generator));

    std::ostringstream s;
    StringConstructor sc(">>>${ABC}<<<", registry);
    sc.constructTo(s);

    ASSERT_EQ(">>>XYZ<<<", s.str());
}
