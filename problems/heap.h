#pragma once

#include <vector>

using namespace std;

void make_heap(vector<int>& nums);

int extract_min(vector<int>& nums);

void decrease_key(vector<int>& nums, int index, int key);

void insert(vector<int>& nums, int key);

void fix_node_bubble_down(vector<int>& nums, int root_index);

void fix_node_bubble_up(vector<int>& nums, int root_index);

int parent_index(int index);

int left_index(int index);

int right_index(int index);