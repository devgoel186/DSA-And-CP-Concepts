#include <iostream>
#include <vector>
using namespace std;

vector<int> *getPath(int **edges, int n, int sv, int ev, bool *visited)
{
    visited[sv] = true;
    if (sv == ev)
    {
        vector<int> *v = new vector<int>;
        v->push_back(sv);
        return v;
    }
    vector<int> *ans = NULL;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            vector<int> *temp = getPath(edges, n, i, ev, visited);
            if (temp != NULL)
            {
                ans = temp;
                break;
            }
        }
    }
    if (ans != NULL)
        ans->push_back(sv);
    return ans;
}

int main()
{
    int n;
    int e;
    cin >> n >> e;

    // Creating adjacency matrix
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        edges[fv][sv] = 1;
        edges[fv][sv] = 1;
    }

    bool *visited = new bool[n];

    // Initialize all vissited array elements by false
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int si;
    cout << "Enter final index to search for path -> ";
    cin >> si;

    vector<int> *final = getPath(edges, n, 0, si, visited);
    // vector<int>::iterator it;
    for (auto it = final->rbegin(); it != final->rend(); it++)
    {
        cout << *it << " ";
    }
    delete[] visited;
}