#include <iostream>
using namespace std;
#include "./BinarySearchTreeNode.h"
#include <algorithm>
#include <climits>
#include <queue>

BinarySearchTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    BinarySearchTreeNode<int> *root = new BinarySearchTreeNode<int>(rootData);

    queue<BinarySearchTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinarySearchTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinarySearchTreeNode<int> *child = new BinarySearchTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinarySearchTreeNode<int> *child = new BinarySearchTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreeLevelWise(BinarySearchTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinarySearchTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinarySearchTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data << " ";
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node<int> *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

template <typename T>
class LL
{
public:
    Node<T> *head;
    Node<T> *tail;

    LL()
    {
        head = NULL;
        tail = NULL;
    }
};

LL<int> *BSTtoLL(BinarySearchTreeNode<int> *root)
{
    if (root == NULL)
    {
        LL<int> *temp = new LL<int>;
        return temp;
    }

    LL<int> *lh = BSTtoLL(root->left);
    LL<int> *rh = BSTtoLL(root->right);

    Node<int> *newNode = new Node<int>(root->data);

    if (lh->tail != NULL)
        lh->tail->next = newNode;
    newNode->next = rh->head;

    LL<int> *final = new LL<int>;

    if (lh->head == NULL)
        final->head = newNode;
    else
        final->head = lh->head;

    if (rh->tail == NULL)
        final->tail = newNode;
    else
        final->tail = rh->tail;

    return final;
}

void printRange(BinarySearchTreeNode<int> *root, int start, int end)
{
    if (root == NULL)
        return;
    if (end < root->data)
        printRange(root->left, start, end);
    else if (start > root->data)
        printRange(root->right, start, end);
    else
    {
        printRange(root->left, start, end);
        if (root->data >= start && root->data <= end)
            cout << root->data << " ";
        printRange(root->right, start, end);
    }
}

BinarySearchTreeNode<int> *searchNode(BinarySearchTreeNode<int> *root, int k)
{
    if (root == NULL)
        return NULL;

    BinarySearchTreeNode<int> *result;

    if (root->data == k)
        return root;
    else if (root->data < k)
        result = searchNode(root->right, k);
    else
        result = searchNode(root->left, k);
    return result;
}

int minimum(BinarySearchTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min({root->data, minimum(root->left), minimum(root->right)});
}

int maximum(BinarySearchTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max({root->data, maximum(root->left), maximum(root->right)});
}

bool isBST(BinarySearchTreeNode<int> *root)
{
    if (root == NULL)
        return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) &&
                  (root->data < rightMin) &&
                  isBST(root->left) &&
                  isBST(root->right);
    return output;
}

class isBSTReturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
};

isBSTReturn isBSTImproved(BinarySearchTreeNode<int> *root)
{
    // Below statements take constant time to execute
    if (root == NULL)
    {
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    // Below two statements take O(n) time complexity,
    // thus making the entire isBSTImproved function to execute
    // in linear time.
    isBSTReturn leftOutput = isBSTImproved(root->left);
    isBSTReturn rightOutput = isBSTImproved(root->right);

    // Below statements take constant time to execute
    int minimum = min({root->data, leftOutput.minimum, rightOutput.minimum});
    int maximum = max({root->data, leftOutput.maximum, rightOutput.maximum});
    bool final = (root->data > leftOutput.maximum) &&
                 (root->data < rightOutput.minimum) &&
                 leftOutput.isBST &&
                 rightOutput.isBST;

    isBSTReturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = final;
    return output;
}

bool isBST3(BinarySearchTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    bool leftCheck = isBST3(root->left, min, root->data);
    bool rightCheck = isBST3(root->right, root->data, max);
    return leftCheck && rightCheck;
}

int main()
{
    // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1

    BinarySearchTreeNode<int> *root = takeInputLevelWise();

    // cout << (isBST(root) ? "Yes" : "No") << endl;
    // bool isBST = isBSTImproved(root).isBST;
    bool isBST = isBST3(root);
    cout << "isBST? -> " << (isBST ? "Yes" : "No") << endl;

    if (isBST)
    {
        printTreeLevelWise(root);
        BinarySearchTreeNode<int> *resultNode = searchNode(root, 7);
        cout << "Result Node data = " << resultNode->data << endl;
        printRange(root, 6, 10);
        cout << endl;
        LL<int> *LLhead = BSTtoLL(root);
        print(LLhead->head);
    }

    delete root;
}
