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

Node *findMidpoint(Node *head)
{
    if (head == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    Node *mid = slow->next;
    slow->next = NULL;
    return mid;
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

Node *merge_sort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *mid = findMidpoint(head);
    // Node *first = head;
    // Node *second = mid->next;
    // mid->next = NULL;
    head = merge_sort(head);
    mid = merge_sort(mid);
    head = merge_sorted_lists(head, mid);

    return head;
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

    cout << "\nThe Merge sorted Linked List is :" << endl;

    head = merge_sort(head);
    print(head);
}