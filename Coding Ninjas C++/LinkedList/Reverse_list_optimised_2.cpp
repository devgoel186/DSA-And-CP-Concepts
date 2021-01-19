/* We actually don't need the Pair class as done in 
* previous implementation, we can simply put 
* `tail = head->next`, before putting `head->next = NULL`
*/

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

Node *reverseLL3(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *subReverse = reverseLL3(head->next);

    Node *tail = head->next;
    tail->next = head;
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
    Node *head1 = takeInputWithTail();

    Node *reverseHead = reverseLL3(head1);
    cout << "\nThe Reversed Linked List is :" << endl;
    print(reverseHead);
}