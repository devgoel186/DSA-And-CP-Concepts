#include <iostream>
using namespace std;
#include "./Node.cpp"

Node *takeInputWithTail()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

Node *merge_sorted_lists(Node *head1, Node *head2)
{
    Node *fhead = NULL;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    if (head1->data < head2->data)
    {
        fhead = head1;
        fhead->next = merge_sorted_lists(head1->next, head2);
    }
    else
    {
        fhead = head2;
        fhead->next = merge_sorted_lists(head1, head2->next);
    }

    return fhead;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head1 = takeInputWithTail();
    Node *head2 = takeInputWithTail();

    cout << "\nThe Merged Linked List is :" << endl;

    Node *head3 = merge_sorted_lists(head1, head2);
    print(head3);
}
