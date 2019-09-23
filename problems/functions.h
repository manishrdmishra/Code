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

bool braces_match(char top, char current)
{
    if (top == '(' && current == ')')
        return true;

    if (top == '[' && current == ']')
        return true;

    if (top == '{' && current == '}')
        return true;

    return false;
}

bool isValid(std::string const &str)
{
    if (str.empty())
        return true;

    std::stack<char> parans;
    parans.push('$');

    for (char ch : str)
    {
        if (braces_match(parans.top(), ch))
        {
            parans.pop();
        }
        else
        {
            parans.push(ch);
        }
    }

    if (parans.top() == '$')
        return true;

    return false;
}