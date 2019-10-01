#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <numeric>

#include <iostream>

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

struct Node
{
    Node(int d, Node *l)
        : data(d), link(l) {}

    int data;
    Node *link;
};

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

[13, 4, 7] should return true, since we can modify 13 to any value 4 or less, to make it non-decreasing.

[13, 4, 1] however, should return false, since there is no way to modify just one element to make the array non-decreasing.
*/

bool check(std::vector<int> &nums)
{
    size_t swapped_count = 0;
    size_t loop_count = 0;

    for (int i = nums.size() - 1; i > 0; --i)
    {
        bool swapped = false;
        ++loop_count;

        for (int j = 0; j < i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }

        if (swapped)
        {
            ++swapped_count;
        }

        if (loop_count >= 2) // run the loop two times
        {
            return swapped_count < loop_count;
        }
    }

    return true;
}
