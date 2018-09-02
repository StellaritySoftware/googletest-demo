#include <gtest/gtest.h>
#include <thread>

TEST(TestSuite1, SucceddedTest)
{
    ASSERT_EQ(1, 1);
}

TEST(TestSuite1, AnotherSucceddedTest)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ASSERT_EQ(1, 1);
}

TEST(TestSuite1, DISABLED_SkippedTest)
{
}

TEST(TestSuite2, FailedTest)
{
    ASSERT_EQ("aaa", "bbb");
}

TEST(TestSuite2, MultipleFailedTest)
{
    EXPECT_EQ("aaa", "bbb");
    EXPECT_EQ(0, 1);
}

TEST(TestSuite2, ExceptionTest)
{
    throw std::runtime_error("exception");
}

class ParamTest : public testing::TestWithParam<int> {};

TEST_P(ParamTest, SucceddedTest) {
    EXPECT_EQ(GetParam(), GetParam());
}

INSTANTIATE_TEST_CASE_P(InstanciatedParamTest,
    ParamTest,
    testing::Range(1, 4));

template <typename T>
class TypedTest : public testing::Test {};

TYPED_TEST_CASE_P(TypedTest);

TYPED_TEST_P(TypedTest, Success) {
    EXPECT_EQ(0U, TypeParam());
}

REGISTER_TYPED_TEST_CASE_P(TypedTest, Success);

typedef testing::Types<unsigned char, unsigned int> UnsignedTypes;
INSTANTIATE_TYPED_TEST_CASE_P(Unsigned, TypedTest, UnsignedTypes);