#include <gtest/gtest.h>
#include "StringView.h"

TEST(StringView, substr)
{
    ASSERT_EQ("", StringView("0123456").substr(7, 1));
    ASSERT_EQ("45", StringView("0123456").substr(4, 2));
    ASSERT_EQ("456", StringView("0123456").substr(4, 4));
}
