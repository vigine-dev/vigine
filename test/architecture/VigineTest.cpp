#include <gtest/gtest.h>

#include <vigine/vigine.h>
#include <vigine/statemachine.h>

#include <memory>

class VigineTest : public ::testing::Test {
public:
  void SetUp() override {}

  void TearDown() override {}
};

template <typename T>
concept MethodCheck_Run = requires(T t)
{
    t.run();
    { t.run() } -> std::same_as<void>;
};

template <typename T>
concept MethodCheck_State = requires(T t)
{
    t.state();
    { t.state() } -> std::same_as<StateMachine*>;
};

TEST(VigineTest, constructor_empty)
{
    std::unique_ptr<Vigine> vigine;
    ASSERT_NO_THROW(vigine = std::make_unique<Vigine>());
    ASSERT_NE(vigine, nullptr);
}

TEST(VigineTest, run_empty_void)
{
    EXPECT_TRUE(MethodCheck_Run<Vigine>) << "Vigine hasn't expected void run() method";
}

TEST(VigineTest, state_empty_void)
{
    EXPECT_TRUE(MethodCheck_State<Vigine>) << "Vigine hasn't expected state() method";
}
