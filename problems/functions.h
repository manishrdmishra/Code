#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <numeric>
#include <cmath>

#include <iostream>

#include "linked_list.h"

using namespace std;

/* Given a string, find the length of the longest substring without repeating characters. */
int lengthOfLongestSubstring(const std::string &str)
{
    if (str.empty())
        return 0;

    size_t max_len = 0;
    std::unordered_map<char, int> char_counts;
    for (auto ch : str)
    {
        if (auto it = char_counts.find(ch); it != char_counts.end())
        {
            max_len = std::max(max_len, char_counts.size());
            char_counts.clear();
        }

        ++char_counts[ch];
    }

    max_len = std::max(max_len, char_counts.size());
    return max_len;
}

/* 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*/

namespace
{
const std::unordered_map<char, char> matching_braces{{'(', ')'},
                                                     {'[', ']'},
                                                     {'{', '}'}};
}

bool braces_match(char top, char current)
{
    auto it = matching_braces.find(top);
    if (it != matching_braces.end())
        return it->second == current;

    return false;
}

bool isValid(std::string const &str)
{
    if (str.empty())
        return true;

    std::stack<char> parans;
    const char sentinel{'$'};
    parans.push(sentinel);

    for (char ch : str)
    {
        if (braces_match(parans.top(), ch))
            parans.pop();
        else
            parans.push(ch);
    }

    if (parans.top() == sentinel)
        return true;

    return false;
}

/* Given a sorted array with possibly duplicated elements, 
find the indices of the first and last occurrences of a target element, x. 
if the target is not found return -1. 
*/
std::pair<int, int> getRange(std::vector<int> const &nums, int target)
{
    const auto equal_it = std::equal_range(nums.cbegin(), nums.cend(), target);

    if (equal_it.first == nums.cend() || equal_it.first == equal_it.second)
        return {-1, -1};

    const auto start = std::distance(nums.cbegin(), equal_it.first);
    const auto end = std::distance(nums.cbegin(), equal_it.second);
    return {start, end - 1};
}

/* Given a singly-linked list, reverse the list. This can be done iteratively or recursively. 
Example:
Input: 4 -> 3 -> 2 -> 1 -> 0 -> NULL
Output: 0 -> 1 -> 2 -> 3 -> 4 -> NULL
*/


Node *reverseRecursively(Node *head)
{
    if (head == nullptr || head->link == nullptr)
    {
        return head;
    }

    auto temp = head->link;
    head->link = nullptr;
    auto node = reverseRecursively(temp);
    temp->link = head;

    return node;
}

Node *reverseIteratively(Node *head)
{
    if (head == nullptr || head->link == nullptr)
        return head;

    auto temp1 = head->link;
    head->link = nullptr;

    while (temp1 != nullptr)
    {
        auto temp2 = temp1->link;
        temp1->link = head;
        head = temp1;
        temp1 = temp2;
    }

    return head;
}

/*Given a list of numbers with only 3 unique numbers (1, 2, 3), sort the list in O(n) time. */

void sortNums(std::vector<int> &nums)
{
    std::array<int, 3> counters{0, 0, 0};

    for (const auto num : nums)
    {
        switch (num)
        {
        case 1:
            ++counters[0];
            break;
        case 2:
            ++counters[1];
            break;
        case 3:
            ++counters[2];
            break;
        }
    }

    std::partial_sum(counters.begin(), counters.end(), counters.begin());

    std::fill(nums.begin(), nums.begin() + counters[0], 1);
    std::fill(nums.begin() + counters[0], nums.begin() + counters[1], 2);
    std::fill(nums.begin() + counters[1], nums.end(), 3);
}

/* You are given a list of numbers, and a target number k. 
Return whether or not there are two numbers in the list that add up to k. */

bool twoSum(std::vector<int> const &nums, int k)
{
    std::set<int> nums_set;

    for (const auto num : nums)
    {
        const auto x = k - num;
        const auto found_it = nums_set.find(x);
        if (found_it != nums_set.end())
            return true;

        nums_set.insert(num);
    }

    return false;
}

/*Given a list of numbers, where every number shows up twice except for one number, find that one number.*/

int singleNumber(std::vector<int> const &nums)
{
    return std::accumulate(nums.begin(), nums.end(), 0, [](auto acc, auto val) {
        return acc ^ val;
    });
}

/*You are given an array of integers in an arbitrary order. Return whether or not it is possible to make the array non-decreasing by modifying at most 1 element to any value.
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
Example:
[13, 4, 7] should return true, since we can modify 13 to any value 4 or less, to make it non-decreasing. [13, 4, 1] however, should return false, since there is no way to modify just one element to make the array non-decreasing.
*/

bool bubbleSortLoop(std::vector<int>& nums)
{
    bool swapped = false;

    for (int j = 0; j < nums.size() - 1; ++j)
    {
        if (nums[j] > nums[j + 1])
        {
            std::swap(nums[j], nums[j + 1]);
            swapped = true;
        }
    }

    return swapped;
}

bool check(std::vector<int> &nums)
{
    auto first_iter_result = bubbleSortLoop(nums);
    auto second_iter_result = bubbleSortLoop(nums);

    return !(first_iter_result && second_iter_result);
}

/*You are given the root of a binary tree. Invert the binary tree in place. That is, all left children should become right children, and all right children should become left children.*/

struct TreeNode
{
    explicit TreeNode(int d, TreeNode *l, TreeNode *r)
        : data(d), left(l), right(r) {}
    int data;
    TreeNode *left;
    TreeNode *right;
};

void preorder(TreeNode *root, std::vector<int> &data_list)
{
    if (!root)
        return;

    data_list.push_back(root->data);
    preorder(root->left, data_list);
    preorder(root->right, data_list);
}

void invert(TreeNode *root)
{
    if (!root)
        return;

    std::swap(root->left, root->right);
    invert(root->left);
    invert(root->right);
}

/*You are given a positive integer N which represents the number of steps in a staircase. You can either climb 1 or 2 steps at a time. Write a function that returns the number of unique ways to climb the stairs.*/
int staircase(int n)
{
    if (n == 1 || n == 2)
        return n;

    int a = 1;
    int b = 2;
    int c;

    for (int i = 2; i < n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

/*Given a list of numbers, find if there exists a pythagorean triplet in that list. A pythagorean triplet is 3 variables a, b, c where a^2 + b^2 = c^2*/

bool findPythagoreanTriplets(const std::vector<int>& nums)
{
    std::vector<int> num_squares;
    num_squares.reserve(nums.size());

    std::transform(nums.cbegin(), nums.cend(), std::back_inserter(num_squares), [](auto x) { return x * x; });
    std::sort(num_squares.begin(), num_squares.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i; j < nums.size(); ++j)
        {
            auto x = std::pow(nums[i], 2) + std::pow(nums[j], 2);
            auto it = std::equal_range(num_squares.cbegin(), num_squares.cend(), x);
            if (it.first != it.second && it.first != num_squares.cend())
            {
                return  true;
            }
        }
    }

    return false;
}

int maxNonAdjacentSum(std::vector<size_t> const &nums)
{
    size_t max_sum = 0;

    size_t sum1 = 0;
    size_t sum2 = 0;
    size_t sum3 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        size_t temp = nums[i] + std::max(sum1, sum2);
        sum1 = sum2;
        sum2 = sum3;
        sum3 = temp;
        max_sum = std::max(max_sum, sum3);
    }

    return max_sum;
}

vector<pair<int, int>> extendedMessageIntervals(string const &str)
{
    vector<pair<int, int>> intervals;

    for (int end = 1; end < str.size();)
    {
        if (str[end - 1] == str[end])
        {
            int start = end - 1;
            while (end < str.size() && str[start] == str[end])
            {
                ++end;
            }

            int len = end - start;
            if (len > 2)
                intervals.push_back({start, end - 1});
        }
        else
        {
            ++end;
        }
    }

    return intervals;
}

vector<string> extendedMessageCombinations(string const& str, string current, int index, vector<pair<int, int>>& intervals, int current_interval)
{

    vector<string> strings;
    if(index > str.size())
    {
        return {current};
    }

    int next = index + 1;
    bool overlaps = false;

    if(current_interval < intervals.size())
    {
        auto interval = intervals[current_interval];
        if(interval.first == index)
        {
            next = interval.second + 1;
            ++current_interval;
            overlaps = true;
        }
    }

    string temp(current);
    temp.push_back(str[index]);

     auto first_set = extendedMessageCombinations(str, temp, next, intervals, current_interval);
     strings.insert(strings.end(), first_set.begin(), first_set.end());

    if(overlaps)
    {
        temp.push_back(str[index]);
        auto second_set = extendedMessageCombinations(str, temp, next, intervals, current_interval);
        strings.insert(strings.end(), second_set.begin(), second_set.end());
    }

    return strings;
}
