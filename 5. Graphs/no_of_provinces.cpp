#include<iostream>
#include<vector>
using namespace std;
// Depth-First Search (DFS) function to traverse the graph starting from a node
void dfs(int node, vector<int> adjLs[], vector<int>& vis)
{
    vis[node] = 1; // Mark the current node as visited
    
    // Iterate through all adjacent nodes of the current node
    for (auto it : adjLs[node])
    {
        // If the adjacent node has not been visited, recursively visit it
        if (!vis[it])
        {
            dfs(it, adjLs, vis);
        }
    }
}

// Function to find the number of connected components in an undirected graph
int findCircleNum(vector<vector<int>>& isConnected) 
{
    int n = isConnected.size(); // Get the number of nodes in the graph
    vector<int> adjLs[n]; // Create an array of adjacency lists to represent the graph

    // Construct the adjacency list representation of the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j); // Add j to the adjacency list of i
                adjLs[j].push_back(i); // Add i to the adjacency list of j (since it's an undirected graph)
            }
        }
    }
    
    vector<int> vis(n, 0); // Create a visited array to keep track of visited nodes
    int count = 0; // Initialize a count to keep track of connected components

    // Iterate through all nodes in the graph
    for (int i = 0; i < n; i++)
    {
        // If the current node has not been visited, perform DFS from it
        if (!vis[i])
        {
            count++; // Increment the count for a new connected component
            dfs(i, adjLs, vis); // Start DFS traversal from the current node
        }
    }

    // Return the count of connected components
    return count;
}
