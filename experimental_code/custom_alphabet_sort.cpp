#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int appendRangeInclusive(char first, char last, int start_index, std::unordered_map<std::string, int>& map)
{

for(;first <= last; ++first)
{
    std::string str;
    str.push_back(first);
    map.emplace(str, start_index);
    ++start_index;
}

return start_index;
}

std::unordered_map<std::string, int>
generateAlpabetToIntMapping()
{
std::unordered_map<std::string, int> map;

int index = 0;
index = appendRangeInclusive('a', 'h', index, map);
map.emplace("ch", index);
index = appendRangeInclusive('i', 'z', index, map);

return map;
}


bool compare(const std::string& first, const std::string& second, const std::unordered_map<std::string, int> map)
{
    if(first.size() == second.size() && first.size() == 0)
    return true;

    auto id1 = 0;
    auto id2 = 0;
    
    while(id1 < first.size() && id2 < second.size())
    {
        auto ch1 = first[id1];
        std::string f(1, ch1);
        
        auto ch2 = second[id2];
        std::string s(1, ch2);

        if(ch1 == 'c' && id1 + 1 < first.size() && first[id1 + 1] == 'h')
        f.push_back('h');

        if(ch2 == 'c' && id2 + 1 < second.size() && second[id2 + 1] == 'h')
        s.push_back('h');

        auto num1 = map.at(f);
        auto num2 = map.at(s);

        if(num1 != num2)
            return num1 < num2;
        
        ++id1;
        ++id2;
    }
    
    if(id1 == first.size())
        return true;
    
    return false;
}

int main()
{
    auto map = generateAlpabetToIntMapping();
    
    auto compare_func = [&map](const std::string& first, const std::string& second)
    {
        return compare(first, second, map);
    };

    std::vector<std::string>words {"indigo", "charisma", "hotel"};
    std::sort(words.begin(), words.end(), compare_func);
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, ", "));
    
    
    std::vector<std::string>words2 {"achn", "ain", "ahn"};
    std::sort(words2.begin(), words2.end(), compare_func);
    std::copy(words2.begin(), words2.end(), std::ostream_iterator<std::string>(std::cout, ", "));
    return 0;
}