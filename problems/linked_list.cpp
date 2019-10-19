#include "linked_list.h"

std::vector<int> to_vector(Node *head)
{
    std::vector<int> elements;
    while (head != nullptr)
    {
        elements.push_back(head->data);
        head = head->link;
    }

    return elements;
}

Node *remove_duplicates(Node *head)
{
    auto temp = head;
    while (temp != nullptr)
    {
        auto temp2 = temp;
        auto val = temp->data;

        while (temp2->link != nullptr)
        {
            if (temp2->link->data == val)
            {
                auto dup = temp2->link;
                temp2->link = temp2->link->link;
                delete dup;
            }
            else
            {
                temp2 = temp2->link;
            }
        }
        temp = temp->link;
    }

    return head;
}

Node *k_th_element_from_last(Node *head, int k)
{
    Node *first = head;
    Node *second = head;

    for (int i = 0; i < k; ++i)
    {
        first = first->link;
    }

    while (first != nullptr)
    {
        first = first->link;
        second = second->link;
    }

    return second;
}