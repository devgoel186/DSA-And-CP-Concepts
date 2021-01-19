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

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *subReverse = reverseLL(head->next);

    Node *temp = subReverse;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return subReverse;
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

    Node *reverseHead = reverseLL(head);
    cout << "\nThe Reversed Linked List is :" << endl;
    print(reverseHead);
}