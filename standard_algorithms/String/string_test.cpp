#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>
#include "String.h"
#include "string_iterator.h"

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

TEST(String, Iterator)
{
    String str("Hello");
    char ch[6];

    int count = 0;
    for(auto it = str.begin(); it != str.end(); ++it)
    {
        ch[count] = *it;
        ++count;
    }
    ch[6] = '\0';
    EXPECT_EQ(strcmp(ch, str.c_str()), 0);
}
