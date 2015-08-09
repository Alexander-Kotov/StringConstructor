#include <gtest/gtest.h>
#include "GeneratorRegistry.h"
#include "Mocks.h"

TEST(GeneratorRegistry, getGenerator)
{
    auto generator = std::make_shared<mocks::Generator>();

    GeneratorRegistry r;
    ASSERT_EQ(std::shared_ptr<IGenerator>(), r.getGenerator("ABC"));
    r.addGenerator("ABC", generator);
    ASSERT_NE(std::shared_ptr<IGenerator>(), r.getGenerator("ABC"));
}
