#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasPath(int **edges, int n, int sv, int ev, bool *visited)
{
    visited[sv] = true;
    bool ans = false;
    if (sv == ev)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            // if (i == ev)
            //     ans = true;
            ans = hasPath(edges, n, i, ev, visited);
            if (ans)
                return ans;
        }
    }
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

    if (hasPath(edges, n, 0, si, visited))
        cout << "True" << endl;
    delete[] visited;
}