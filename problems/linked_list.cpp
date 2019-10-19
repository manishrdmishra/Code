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