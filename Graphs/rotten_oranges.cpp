#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size(); // Get the number of rows in the grid
    int m = grid[0].size(); // Get the number of columns in the grid
    
    queue<pair<pair<int, int>, int>> q; // Create a queue to perform BFS
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Create a 2D array to track visited cells
    
    // Step 1: Initialize the queue and visited array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2) // If a cell contains a rotten orange
            {
                q.push({{i, j}, 0}); // Push its position and time (0) into the queue
                vis[i][j] = 2; // Mark it as visited and rotten
            }
            else
            {
                vis[i][j] = 0; // Mark it as unvisited
            }
        }
    }
    
    int time = 0; // Initialize the time
    
    // Step 2: Perform BFS to spread the rot
    while (!q.empty())
    {
        int r = q.front().first.first; // Get row of the current rotten orange
        int c = q.front().first.second; // Get column of the current rotten orange
        int t = q.front().second; // Get the time (minutes) at which this orange became rotten
        q.pop(); // Remove the current orange from the queue
        
        time = max(time, t); // Update the maximum time
        
        int dRow[] = {-1, 0, 1, 0}; // Define the possible row offsets for adjacent cells
        int dCol[] = {0, 1, 0, -1}; // Define the possible column offsets for adjacent cells
        
        // Iterate through all possible directions (up, right, down, left)
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + dRow[i]; // Calculate the row of the adjacent cell
            int ncol = c + dCol[i]; // Calculate the column of the adjacent cell
            
            // Check if the adjacent cell is within the grid, not rotten, and has a fresh orange
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1}); // Push the position and time of the adjacent fresh orange into the queue
                vis[nrow][ncol] = 2; // Mark the adjacent cell as visited and rotten
            }
        }
    }
    
    // Step 3: Check if there are any remaining fresh oranges in the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 2 && grid[i][j] == 1) // If there's a fresh orange that hasn't been visited by BFS
            {
                return -1; // Return -1, indicating that not all oranges can be rotten
            }
        }
    }
    
    // Step 4: Return the maximum time taken for all oranges to become rotten
    return time;
}
