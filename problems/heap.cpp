#include "heap.h"

#include <numeric>
#include <limits>
#include <stdexcept>

void make_heap(vector<int>& nums)
{
    for(int i = nums.size()/2; i >= 0 ; --i)
    {
        fix_node_bubble_down(nums, i);
    }
}

int extract_min(vector<int>& nums)
{
    if(nums.empty())
        throw runtime_error(" heap is empty ");

    int top = nums.front();
    swap(nums.front(), nums.back());
    nums.pop_back();
    fix_node_bubble_down(nums, 0);
    return top;
}

void insert(vector<int>& nums, int key)
{
    nums.push_back(key);
    fix_node_bubble_up(nums, nums.size() - 1);
}

void decrease_key(vector<int>& nums, int index, int key)
{
    nums[index] = key;
    fix_node_bubble_up(nums, index);
}

void fix_node_bubble_down(vector<int>& nums, int root_index)
{
    int left = left_index(root_index);
    int right = right_index(root_index);

    int updated_index = root_index;
    if(left < nums.size() && nums[root_index] > nums[left])
    {
        updated_index = left;
    }

    if(right < nums.size() && nums[updated_index] > nums[right])
    {
        updated_index = right;
    }

    if(updated_index != root_index)
    {
        swap(nums[root_index], nums[updated_index]);
        fix_node_bubble_down(nums, updated_index);
    }

}

void fix_node_bubble_up(vector<int>& nums, int index)
{
    int parent = parent_index(index);
    if(parent >=0 && nums[parent] > nums[index])
    {
        swap(nums[parent], nums[index]);
        fix_node_bubble_up(nums, parent);
    }
}

int left_index(int index)
{
    return 2 * index + 1;
}

int right_index(int index)
{
    return 2 * index + 2;
}

int parent_index(int index)
{
    return index/2;
}