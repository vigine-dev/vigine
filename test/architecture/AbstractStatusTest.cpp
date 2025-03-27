#include <gtest/gtest.h>

#include <vigine/abstractstatus.h>
#include <vigine/vigine.h>
#include "concepts.h"

#include <memory>

TEST(AbstractStatusTest, check_isAbstract) {
  EXPECT_TRUE((IsAbstract<AbstractStatus>))
      << "AbstractStatus isn't an abstract";
}

TEST(AbstractStatusTest, method_destructor) {
  EXPECT_TRUE((HasMethod_destructor<AbstractStatus>))
      << "AbstractStatus hasn't correct destructor";
}
