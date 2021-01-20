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

Node *reverseLL_iterative(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = head->next;
    while (next != NULL)
    {
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }
    current->next = prev;
    return current;
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
    Node *head = takeInputWithTail();

    Node *reverseHead = reverseLL_iterative(head);
    cout << "\nThe Reversed Linked List is :" << endl;
    print(reverseHead);
}