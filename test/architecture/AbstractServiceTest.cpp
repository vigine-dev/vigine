#include <gtest/gtest.h>

#include <vigine/abstractservice.h>
#include <vigine/vigine.h>
#include "concepts.h"

#include <memory>

TEST(AbstractServiceTest, check_isAbstract) {
  EXPECT_TRUE((IsAbstract<AbstractService>))
      << "AbstractService isn't an abstract";
}

TEST(AbstractServiceTest, method_destructor) {
  EXPECT_TRUE((HasMethod_destructor<AbstractService>))
      << "AbstractService hasn't correct destructor";
}
