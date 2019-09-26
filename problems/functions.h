#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>

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

Node* reverseRecursively(Node *head)
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

// Node* reverseIteratively(Node* head)
// {
//     if(head == nullptr || head->link == nullptr)
//         return head;

//     while(head->link != nullptr && head->link->link != nullptr)
//     {
//         auto temp1 = head->link;
//         head->link = nullptr;
//         head = temp1->link;
//     }
//}