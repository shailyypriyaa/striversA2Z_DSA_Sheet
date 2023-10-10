#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    // Create a vector to store the BFS traversal result
    vector<int> bfs;
    
    // Create a vector to keep track of visited nodes, initialize to 0 (not visited)
    vector<int> visited(V, 0);
    
    // Start the BFS traversal from the first node (node 0)
    visited[0] = 1; // Mark the first node as visited
    
    // Create a queue for BFS traversal and enqueue the first node
    queue<int> q;
    q.push(0);

    // Perform BFS traversal
    while (!q.empty())
    {
        // Dequeue the front node from the queue
        int u = q.front();
        q.pop();

        // Add the dequeued node to the BFS result
        bfs.push_back(u);

        // Visit all neighbors (adjacent nodes) of the current node
        for (auto v : adj[u])
        {
            // If the neighbor is not visited, mark it as visited and enqueue it
            if (!visited[v])
            {
                visited[v] = 1; // Mark the neighbor as visited
                q.push(v);      // Enqueue the neighbor for further traversal
            }
        }
    }

    // Return the BFS traversal result
    return bfs;
}
