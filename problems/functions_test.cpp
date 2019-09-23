#include <gtest/gtest.h>

#include "functions.h"

TEST(lognest_substring_without_repeated_chars, empty_string)
{
    EXPECT_EQ(0, lengthOfLongestSubstring(""));
}

TEST(lognest_substring_without_repeated_chars, arbitary_string)
{
    EXPECT_EQ(10, lengthOfLongestSubstring("abrkaabcdefghijjxxx"));
}

TEST(lognest_substring_without_repeated_chars, string_with_one_char)
{
    EXPECT_EQ(1, lengthOfLongestSubstring("a"));
}

TEST(lognest_substring_without_repeated_chars, string_with_two_similar_char)
{
    EXPECT_EQ(1, lengthOfLongestSubstring("aa"));
}

TEST(lognest_substring_without_repeated_chars, string_with_two_different_repeated_chars)
{
    EXPECT_EQ(2, lengthOfLongestSubstring("aabb"));
}

TEST(lognest_substring_without_repeated_chars, string_with_two_different_chars_and_repeated_char)
{
    EXPECT_EQ(2, lengthOfLongestSubstring("abbbbbbbbb"));
}

TEST(lognest_substring_without_repeated_chars, string_with_repeated_chars_and_two_different_char)
{
    EXPECT_EQ(2, lengthOfLongestSubstring("aaaaaaab"));
}

TEST(valid_paran, empty_string)
{
    EXPECT_EQ(true, isValid(""));
}

TEST(valid_paran, valid_string)
{
    EXPECT_EQ(true, isValid("((()))"));
}

TEST(valid_paran, valid_string_length_6)
{
    EXPECT_EQ(true, isValid("[()]{}"));
}

TEST(valid_paran, invalid_string)
{
    EXPECT_EQ(false, isValid("({[)]"));
}

TEST(valid_paran, invalid_string_only_open_braces)
{
    EXPECT_EQ(false, isValid("(((("));
}

TEST(valid_paran, invalid_string_only_close_braces)
{
    EXPECT_EQ(false, isValid(")))))"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}