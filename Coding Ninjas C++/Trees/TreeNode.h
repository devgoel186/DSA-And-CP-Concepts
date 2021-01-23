// #include <iostream>
// using namespace std;
#include <vector>

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode() // Destructor function to delete entire tree
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            delete children[i];
        }
    }
};