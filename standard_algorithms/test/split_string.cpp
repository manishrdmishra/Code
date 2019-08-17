#include <gtest/gtest.h>

#include <split_string.h>

TEST(split_string, by_new_line_delimeter)
{
    std::string text{"hello\nhi\nhow are you\n I am good"};
    std::vector<std::string> expected_string{"hello", "hi", "how are you", " I am good"};

    auto splited_strings = split_by(text, '\n');
    EXPECT_EQ(expected_string, splited_strings);
}

TEST(split_string, by_comma_delimiter)
{
    std::string text{"hello,hi,how are you"};
    std::vector<std::string> expected_string{"hello", "hi", "how are you"};

    auto splited_strings = split_by(text, ',');
    EXPECT_EQ(expected_string, splited_strings);
}

TEST(split_string, by_comma_delimeter_of_string_without_comma)
{
    std::string text{"hellohihow are you"};
    std::vector<std::string> expected_string{"hellohihow are you"};

    auto splited_strings = split_by(text, ',');
    EXPECT_EQ(expected_string, splited_strings);
}

TEST(split_string, by_comma_delimeter_of_string_which_contains_only_delimeter)
{
    std::string text{","};
    auto splited_strings = split_by(text, ',');

    EXPECT_EQ(splited_strings.size(), 1);
    EXPECT_EQ(splited_strings.at(0).size(), 0);
}