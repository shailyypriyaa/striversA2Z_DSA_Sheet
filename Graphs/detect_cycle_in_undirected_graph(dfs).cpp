#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Function to perform depth-first search (DFS) to check for cycles in a graph.
// 'src' is the current node, 'parent' is the parent node, 'adj' is the adjacency list,
// and 'vis' is the array to track visited nodes.
bool dfs(int src, int parent, vector<int> adj[], int vis[])
{
    vis[src] = 1; // Mark the current node as visited.

    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            // If the adjacent node has not been visited, recursively call DFS on it.
            if (dfs(it, src, adj, vis) == true)
            {
                return true; // If a cycle is found in the subtree, return true.
            }
        }
        else if (parent != it)
        {
            // If the adjacent node has been visited and is not the parent node,
            // then a back edge is found, indicating a cycle in the graph.
            return true;
        }
    }

    return false; // No cycle found in the current subtree.
}

// Function to detect cycles in an undirected graph.
bool detectCycle(int V, vector<int> adj[])
{
    // Create an array 'vis' to track visited nodes.
    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            // Start DFS from unvisited nodes and check for cycles.
            if (dfs(i, -1, adj, vis) == true)
            {
                return true; // If a cycle is found, return true.
            }
        }
    }

    return false; // No cycle found in the entire graph.
}
