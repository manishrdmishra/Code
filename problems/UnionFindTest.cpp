#include "UnionFind.h"

#include <gtest/gtest.h>


TEST(UnionFind, unionfind1)
{
    UnionFind unionFind(10);

    unionFind.union_set(0, 3);
    unionFind.union_set(0, 2);
    unionFind.union_set(3, 4);

    EXPECT_EQ(0, unionFind.find_set(3));
    EXPECT_EQ(0, unionFind.find_set(4));

    EXPECT_EQ(5, unionFind.find_set(5));

    unionFind.union_set(5, 6);
    unionFind.union_set(7, 8);
    unionFind.union_set(5, 8);

    EXPECT_EQ(5, unionFind.find_set(7));
    EXPECT_EQ(5, unionFind.find_set(8));
}