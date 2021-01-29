#ifndef NULLPTR_TEST_H_
#define NULLPTR_TEST_H_

#include "test.h"

TEST(NullptrTest, NullptrTest) {
    Configurations c;
    c.setGlobally(el::ConfigurationType::Format, "%level %msg");
    c.set(el::Level::Verbose, el::ConfigurationType::Format, "%level-%vlevel %msg");
    el::Loggers::reconfigureLogger(consts::kDefaultLoggerId, c);

    char* nullString = nullptr;
    LOG(DEBUG) << "null string: " << nullString;
    LOG(DEBUG) << "another string";
    EXPECT_EQ("DEBUG another string", tail(1));
}

#endif // NULLPTR_TEST_H_
