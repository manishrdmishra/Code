#include <iostream>
#include <gtest/gtest.h>
#include "String.h"

using String = library::String;
TEST(String, constructorWithGivenChars)
{
      String str ("Hello World");
      EXPECT_EQ(strcmp(str.c_str(), "Hello World"),0);
}

TEST(String, defaultConstructor)
{
      String str;
      EXPECT_EQ(str.length(),0);
}

TEST(String, copyConstructor)
{
      String str1 ("Hello World");
      String str2(str1);
      EXPECT_EQ(strcmp(str2.c_str(), "Hello World"),0);
}

TEST(String, indexedAccessMethod)
{
      String str1 ("Hello");
      EXPECT_EQ(str1[0], 'H');
      EXPECT_EQ(str1[1], 'e');
      EXPECT_EQ(str1[2], 'l');
      EXPECT_EQ(str1[3], 'l');
      EXPECT_EQ(str1[4], 'o');
}
