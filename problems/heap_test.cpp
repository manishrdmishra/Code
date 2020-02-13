#include "heap.h"

#include <gtest/gtest.h>

TEST(heapify, list_with_6_elements)
{
    vector<int> list{5, 8, 1, 2, 10, 4};
    make_heap(list);

    vector<int> expected{1, 2, 4, 8, 10, 5};
    EXPECT_EQ(list, expected);

    vector<int> list2{8, 5, 4, 2, 10, 1};
    vector<int> expected2{1, 2, 4, 5, 10, 8};
}

TEST(heapify, list_with_2_elements)
{
    vector<int> list{8, 5};
    make_heap(list);

    vector<int> expected{5, 8};
    EXPECT_EQ(list, expected);
}

TEST(heapify, list_with_1_elements)
{
    vector<int> list{8};
    make_heap(list);

    vector<int> expected{8};
    EXPECT_EQ(list, expected);
}

TEST(extract_min, from_list_with_6_elements)
{
    vector<int> list{5, 8, 1, 2, 10, 4};
    make_heap(list);

    vector<int> extracted;

    for(int i = 0; i < 6; ++i)
    {
        extracted.push_back(extract_min(list));
    }

    vector<int> sorted{1, 2, 4, 5, 8, 10};
    EXPECT_EQ(extracted, sorted);

}

TEST(extract_min, from_list_with_10_elements)
{
    vector<int> list{5, 8, 1, 2, 10, 4, 20, 15, 6, 12};
    make_heap(list);

    vector<int> extracted;

    for(int i = 0; i < 10; ++i)
    {
        extracted.push_back(extract_min(list));
        //std::copy(list.begin(), list.end(), ostream_iterator<int>(cout, ", "));
        //cout << endl;
    }

    vector<int> sorted{1, 2, 4, 5, 6, 8, 10, 12, 15, 20};
    EXPECT_EQ(extracted, sorted);
}

TEST(insert, to_list_of_10_elements)
{
    vector<int> list{5, 8, 25, 2, 10, 4, 20, 15, 6, 12};
    make_heap(list);

    insert(list, 1);

    EXPECT_EQ(1, extract_min(list));
    EXPECT_EQ(2, extract_min(list));
}

TEST(decrease_key, in_list_of_10_elements)
{
    vector<int> list{5, 8, 25, 2, 10, 4, 20, 15, 6, 12};
    make_heap(list);

    decrease_key(list, 5, -6);
    EXPECT_EQ(-6, extract_min(list));
}