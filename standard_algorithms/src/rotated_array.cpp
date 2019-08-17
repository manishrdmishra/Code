#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
    public:
        int search(std::vector<int>& nums, int target) {

            const auto pivot = std::adjacent_find(nums.begin(), nums.end(), [](auto first, auto second){

                    if(first > second ) 
                    return true;

                    return false;

                    });


            // search in two arrays 

            auto range = std::equal_range(nums.begin(), pivot + 1 , target);
            if(range.first != ( pivot + 1 ) ) 
                return std::distance(nums.begin(), range.first);


            range = std::equal_range( pivot + 1 , nums.end(), target);
            if ( range.first != nums.end() ) 
                return std::distance(nums.begin(), range.first);


            return -1;

        }


};

int main()
{
    Solution s;
    std::vector<int> val{4, 5, 6, 7, 0, 1, 2};
    auto r = s.search(val, 0);
    std::cout << " result :"  << r << std::endl;
    return 0;

}
