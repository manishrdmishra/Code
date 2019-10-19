#include <gtest/gtest.h>

#include <vector>
#include "linked_list.h"

TEST(linked_list, remove_duplicates_one)
{
    auto node4 = new Node(1, nullptr);
    auto node3 = new Node(3, node4);
    auto node2 = new Node(0, node3);
    auto node1 = new Node(2, node2);
    auto head = new Node(1, node1);

    auto new_head = remove_duplicates(head);

    std::vector<int> expected{1, 2, 0, 3};
    EXPECT_EQ(expected, to_vector(new_head));
}

TEST(linked_list, remove_duplicates_all)
{
    auto node4 = new Node(1, nullptr);
    auto node3 = new Node(1, node4);
    auto node2 = new Node(1, node3);
    auto node1 = new Node(1, node2);
    auto head = new Node(1, node1);

    auto new_head = remove_duplicates(head);

    std::vector<int> expected{1};
    EXPECT_EQ(expected, to_vector(new_head));
}

TEST(linked_list, remove_duplicates_two_elements)
{
    auto node1 = new Node(1, nullptr);
    auto head = new Node(1, node1);

    auto new_head = remove_duplicates(head);

    std::vector<int> expected{1};
    EXPECT_EQ(expected, to_vector(new_head));
}

TEST(linked_list, remove_duplicates_two)
{
    auto node4 = new Node(1, nullptr);
    auto node3 = new Node(2, node4);
    auto node2 = new Node(1, node3);
    auto node1 = new Node(2, node2);
    auto head = new Node(1, node1);

    auto new_head = remove_duplicates(head);

    std::vector<int> expected{1, 2};
    EXPECT_EQ(expected, to_vector(new_head));
}

TEST(linked_list, remove_duplicates_none)
{
    auto node4 = new Node(5, nullptr);
    auto node3 = new Node(2, node4);
    auto node2 = new Node(3, node3);
    auto node1 = new Node(0, node2);
    auto head = new Node(1, node1);

    auto new_head = remove_duplicates(head);

    std::vector<int> expected{1, 0, 3, 2, 5};
    EXPECT_EQ(expected, to_vector(new_head));
}

TEST(linked_list, remove_duplicates_empty_list)
{
    auto head = nullptr; 

    auto new_head = remove_duplicates(head);

    std::vector<int> expected{};
    EXPECT_EQ(expected, to_vector(new_head));
}

TEST(linked_list, 2nd_element_from_last)
{
    auto node4 = new Node(5, nullptr);
    auto node3 = new Node(2, node4);
    auto node2 = new Node(3, node3);
    auto node1 = new Node(0, node2);
    auto head = new Node(1, node1);

    auto node = k_th_element_from_last(head, 2);

    EXPECT_EQ(2, node->data);
}

TEST(linked_list, 1st_element_from_last)
{
    auto node4 = new Node(5, nullptr);
    auto node3 = new Node(2, node4);
    auto node2 = new Node(3, node3);
    auto node1 = new Node(0, node2);
    auto head = new Node(1, node1);

    auto node = k_th_element_from_last(head, 1);

    EXPECT_EQ(5, node->data);
}

TEST(linked_list, 5th_element_from_last)
{
    auto node4 = new Node(5, nullptr);
    auto node3 = new Node(2, node4);
    auto node2 = new Node(3, node3);
    auto node1 = new Node(0, node2);
    auto head = new Node(1, node1);

    auto node = k_th_element_from_last(head, 5);

    EXPECT_EQ(1, node->data);
}


