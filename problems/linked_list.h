#pragma once

#include <vector>

struct Node
{
    Node(int d, Node *l)
        : data(d), link(l) {}

    int data;
    Node *link;
};

Node *remove_duplicates(Node *head);

std::vector<int> to_vector(Node *head);

Node *k_th_element_from_last(Node *head, int k);
