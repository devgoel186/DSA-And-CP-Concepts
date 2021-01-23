#include <iostream>
using namespace std;
#include "./TreeNode.h"
#include <queue>

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data:" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter data:" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << " child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int numNodes(TreeNode<int> *root) //Calculates number of nodes recursively
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

void printTree(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

int calculateHeight(TreeNode<int> *root)
{
    int max = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int ans = calculateHeight(root->children[i]);
        if (ans > max)
            max = ans;
    }
    return max + 1;
}

int countLeafs(TreeNode<int> *root)
{
    if (root->children.size() == 0)
        return 1;
    int leafs = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        leafs += countLeafs(root->children[i]);
    }
    return leafs;
}

void printAtDepthK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtDepthK(root->children[i], k - 1);
    }
}

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    // Tree data - 1 3 2 3 4 2 5 6 0 0 0 0

    TreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    cout << "\nPreorder traversal : ";
    preOrder(root);
    cout << "\nPostorder traversal : ";
    postOrder(root);
    cout << endl;

    cout << "Height = " << calculateHeight(root) << endl;
    int k;

    cout << "Enter level number to print elements:";
    cin >> k;
    printAtDepthK(root, k);

    cout << "Number of Leafs = " << countLeafs(root) << endl;

    delete root; // We have created a custom destructor in the class file
                 // to delete the tree and its children from heap memory
                 // Deleting root here will call the destructor function
                 // of the class.

    /* deleteTree(root); // Or instead of using destructor, we can call this
                      // function created in this file which will delete the
                      // tree recursively.*/
}
