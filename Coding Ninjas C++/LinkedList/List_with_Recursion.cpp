#include <iostream>
using namespace std;
#include "./Node.cpp"

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

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

Node *insertNode(Node *head, int i, int data)
{
    if (i <= 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    head->next = insertNode(head->next, i - 1, data);
    return head;
}

Node *deleteNode(Node *head, int i)
{
    if (i <= 0)
    {
        head = head->next;
        return head;
    }

    head->next = deleteNode(head->next, i - 1);
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    // Node *head = takeInput();
    Node *head2 = takeInputWithTail();

    // cout << "\nThe Linked List is :" << endl;
    cout << "\nThe Linked List is :" << endl;

    // print(head);
    print(head2);

    cout << "Enter data for node to be inserted" << endl;

    int i, data;
    cin >> i >> data;

    head2 = insertNode(head2, i, data);

    cout << "\nThe new Linked List is :" << endl;
    print(head2);

    cout << "Enter data for node to be deleted" << endl;

    cin >> i;

    head2 = deleteNode(head2, i);

    cout << "\nThe new Linked List is :" << endl;
    print(head2);
}