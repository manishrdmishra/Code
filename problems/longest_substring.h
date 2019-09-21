#include <unordered_map>
#include <algorithm>
#include <string>

/* Given a string, find the length of the longest substring without repeating characters. */
int lengthOfLongestSubstring(const std::string& str)
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