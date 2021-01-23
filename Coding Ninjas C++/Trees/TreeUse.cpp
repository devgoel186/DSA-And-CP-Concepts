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

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout << "Height = " << calculateHeight(root) << endl;
    int k;
    cout << "Enter level number to print elements:";
    cin >> k;
    printAtDepthK(root, k);
    cout << "Number of Leafs = " << countLeafs(root) << endl;
}
