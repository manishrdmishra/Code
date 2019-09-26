#include <gtest/gtest.h>

#include <vector>
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

TEST(getRange, empty_array)
{
    const std::pair<int, int> expected{-1, -1};
    EXPECT_EQ(expected, getRange(std::vector<int>(), 1));
}

TEST(getRange, array_with_repeated_target)
{
    const std::pair<int, int> expected{6, 8};
    EXPECT_EQ(expected, getRange({1, 3, 3, 5, 7, 8, 9, 9, 9, 15}, 9));
}

TEST(getRange, array_with_repeated_target2)
{
    const std::pair<int, int> expected{1, 2};
    EXPECT_EQ(expected, getRange({100, 150, 150, 153}, 150));
}

TEST(getRange, array_with_)
{
    const std::pair<int, int> expected{0, 0};
    EXPECT_EQ(expected, getRange({100, 150, 150, 153}, 100));
}

TEST(getRange, array_with_single_element_which_is_target)
{
    const std::pair<int, int> expected{0, 0};
    EXPECT_EQ(expected, getRange({1}, 1));
}

TEST(getRange, array_with_only_target_elements)
{
    const std::pair<int, int> expected{0, 4};
    EXPECT_EQ(expected, getRange({1, 1, 1, 1, 1}, 1));
}

TEST(getRange, array_without_target)
{
    const std::pair<int, int> expected{-1, -1};
    EXPECT_EQ(expected, getRange({1, 2, 3, 4, 5, 6, 10}, 9));
}

TEST(getRange, array_without_target_which_lies_in_the_min_and_max_value_of_array)
{
    const std::pair<int, int> expected{-1, -1};
    EXPECT_EQ(expected, getRange({1, 2, 3, 4, 5, 6, 8, 9, 10}, 7));
}

TEST(getRange, array_without_target_which_is_smaller_than_min_element_in_array)
{
    const std::pair<int, int> expected{-1, -1};
    EXPECT_EQ(expected, getRange({3, 4, 5, 6, 8, 9, 10}, 1));
}

TEST(getRange, array_without_target_which_is_greater_than_max_element_in_array)
{
    const std::pair<int, int> expected{-1, -1};
    EXPECT_EQ(expected, getRange({3, 4, 5, 6, 8, 9, 10}, 15));
}

TEST(reverse_list_recursively, list_with_no_elements)
{
    auto head =  nullptr;

    auto reversed= reverseRecursively(head);
    std::vector<int> elements;
    while (reversed != nullptr)
    {
        elements.push_back(reversed->data);
        reversed = reversed->link;
    }

    EXPECT_EQ(0, elements.size());
}

TEST(reverse_list_recursively, list_with_1_elements)
{
    auto head = new Node(1, nullptr);

    auto reversed= reverseRecursively(head);
    std::vector<int> elements;
    while (reversed != nullptr)
    {
        elements.push_back(reversed->data);
        reversed = reversed->link;
    }

    std::vector<int> expected{1};
    EXPECT_EQ(expected, elements);
}

TEST(reverse_list_recursively, list_with_2_elements)
{
    auto node1 = new Node(2, nullptr);
    auto head = new Node(1, node1);

    auto reversed= reverseRecursively(head);
    std::vector<int> elements;
    while (reversed != nullptr)
    {
        elements.push_back(reversed->data);
        reversed = reversed->link;
    }

    std::vector<int> expected{2, 1};
    EXPECT_EQ(expected, elements);
}

TEST(reverse_list_recursively, list_with_4_elements)
{
    auto node4 = new Node(4, nullptr);
    auto node3 = new Node(3, node4);
    auto node2 = new Node(0, node3);
    auto node1 = new Node(2, node2);
    auto head = new Node(1, node1);

    auto reversed= reverseRecursively(head);
    std::vector<int> elements;
    while (reversed != nullptr)
    {
        elements.push_back(reversed->data);
        reversed = reversed->link;
    }

    std::vector<int> expected{4, 3, 0, 2, 1};
    EXPECT_EQ(expected, elements);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}