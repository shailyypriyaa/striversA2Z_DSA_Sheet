#include<iostream>
#include<vector>
using namespace std;
// Depth-First Search (DFS) function to traverse the graph starting from a vertex
void dfs(int vertex, vector<int> adj[], vector<int> &v, vector<bool> &vis)
{
    // Mark the current vertex as visited
    vis[vertex] = true;
    
    // Add the current vertex to the DFS traversal result
    v.push_back(vertex);
    
    // Explore all neighbors (adjacent vertices) of the current vertex
    for (auto u : adj[vertex])
    {
        // If the neighbor has not been visited yet, recursively visit it
        if (vis[u] == false)
        {
            dfs(u, adj, v, vis);
        }
    }
}

// Function to perform DFS traversal of a graph
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Create a vector to store the DFS traversal result
    vector<int> v;
    
    // Create a vector to keep track of visited vertices, initialized to 'false'
    vector<bool> vis(V, false);
    
    // Start DFS traversal from the source vertex (in this case, source vertex is 0)
    dfs(0, adj, v, vis);
    
    // Return the DFS traversal result
    return v;
}
