
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *getMiddle(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}
Node *findMiddle(Node *head)
{

    return getMiddle(head);
}