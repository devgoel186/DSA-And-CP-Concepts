/* The previous code of reversing the linked list required
* calling recursion on the next pointer to head and then 
* traversing through the linked list and finding the last
* element. This process takes O(n^2) time.

* T(n) = T(n-1) + k(n-1)
* T(n-1) = T(n-2) + k(n-2)
* T(n-2) = T(n-3) + k(n-3)
* ---------------------
* ---------------------
* ---------------------
* ---------------------
* T(2) = T(1) + k
* => T(n) = k(n(n-1)/2)
* Therefore, complexity = O(n^2)
* To optimise the code, we do the following changes
*/

#include <iostream>
using namespace std;
#include "./Node.cpp"

class Pair
{
public:
    Node *head;
    Node *tail;
};

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

Pair reverseLL2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair subReverse = reverseLL2(head->next);

    subReverse.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = subReverse.head;
    ans.tail = head;
    return ans;
}

Node *getReverseLL2(Node *head)
{
    return reverseLL2(head).head;
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

    Node *reverseHead = getReverseLL2(head1);
    cout << "\nThe Reversed Linked List is :" << endl;
    print(reverseHead);
}