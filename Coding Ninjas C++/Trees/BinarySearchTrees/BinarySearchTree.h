#include <iostream>
#include <queue>
#include "./BinarySearchTreeNode.h"
using namespace std;

class BST
{
    BinarySearchTreeNode<int> *root;

private:
    BinarySearchTreeNode<int> *deleteData(int data, BinarySearchTreeNode<int> *node)
    {
        if (node == NULL)
            return NULL;

        if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinarySearchTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinarySearchTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinarySearchTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
    }

    BinarySearchTreeNode<int> *insert(int data, BinarySearchTreeNode<int> *node)
    {
        if (node == NULL)
            return new BinarySearchTreeNode<int>(data);

        if (data < node->data)
            node->left = insert(data, node->left);
        else
            node->right = insert(data, node->right);
        return node;
    }

    bool hasData(int data, BinarySearchTreeNode<int> *node)
    {
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        else if (data < root->data)
            return hasData(data, root->left);
        else
            return hasData(data, node->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
        root = deleteData(data, root);
    }

    void insert(int data)
    {
        root = insert(data, root);
    }

    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void printTreeLevelWise()
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
};