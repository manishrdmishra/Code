#include <iostream>
#include <vector>

int second_largest(const std::vector<int>& nums)
{
    if(nums.size() < 2)
        throw std::runtime_error("not enough number of elements");
    
    auto second_largest = nums[0];
    auto largest = nums[1];

    for(auto num : nums)
    {
        if(largest < num)
        {
            second_largest = largest;
            largest = num;
        }
    }

    if(largest == second_largest)
        throw std::runtime_error("all elements are equal");
        
    return second_largest;
}

int main()
{

    std::cout << second_largest({4, 1, 17, 12, 20}) << std::endl;
    std::cout << second_largest({20, 12, 5, 1, 8}) << std::endl;
    std::cout << second_largest({-5, -8}) << std::endl;

}