#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Depth-First-Search Approach (DFS)
void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, i, visited);
        }
    }
}

// Breadth-First-Search (BFS)
void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    while (!pending.empty())
    {
        int currentVertex = pending.front();
        pending.pop();
        cout << currentVertex << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
                continue;
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }
    delete[] visited;
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete[] visited;
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

    cout << "DFS Traversal : ";
    DFS(edges, n);

    cout << "\nBFS Traversal : ";
    BFS(edges, n);
}