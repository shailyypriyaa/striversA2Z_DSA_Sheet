#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Function to check for cycles starting from a specific source vertex.
bool isCycle(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;  // Mark the current vertex as visited.
    queue<pair<int, int>> q;
    q.push({src, -1}); // Queue to perform BFS, -1 represents no parent.

    while (!q.empty())
    {
        int curr = q.front().first;  // Get the current vertex.
        int parent = q.front().second;  // Get the parent vertex.
        q.pop();

        // Explore all adjacent vertices of the current vertex.
        for (auto it : adj[curr])
        {
            if (!vis[it])
            {
                // If the adjacent vertex has not been visited, mark it as visited and enqueue it.
                vis[it] = 1;
                q.push({it, curr});  // The 'curr' vertex is now the parent of 'it'.
            }
            else if (parent != it)
            {
                // If the adjacent vertex has been visited but is not the parent, a cycle is detected.
                return true;  // A cycle is present in the graph.
            }
        }
    }
    return false;  // No cycles were detected starting from the 'src' vertex.
}

// Function to detect cycles in an undirected graph.
bool detectCycle(int V, vector<int> adj[])
{
    // Initialize an array to track visited vertices.
    int vis[V] = {0};

    // Iterate through all vertices to check for cycles in disconnected components.
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i, adj, vis))
            {
                return true;  // A cycle was detected in the graph.
            }
        }
    }
    return false;  // No cycles were detected in the entire graph.
}
