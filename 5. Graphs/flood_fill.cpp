#include<iostream>
#include<vector>
using namespace std;
// Depth-First Search (DFS) function to fill a region in the image with the specified color
void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image,
         int inicol, int delRow[], int delCol[], int color)
{
    ans[row][col] = color; // Fill the current pixel with the new color
    int n = image.size(); // Get the number of rows in the image
    int m = image[0].size(); // Get the number of columns in the image

    // Iterate through all possible directions (up, right, down, left)
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i]; // Calculate the row of the adjacent pixel
        int ncol = col + delCol[i]; // Calculate the column of the adjacent pixel

        // Check if the adjacent pixel is within the bounds of the image, has the same initial color,
        // and has not been filled with the new color
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicol && ans[nrow][ncol] != color)
        {
            dfs(nrow, ncol, ans, image, inicol, delRow, delCol, color); // Recursively fill the adjacent pixel
        }
    }
}

// Function to perform flood fill on the image starting from the specified pixel
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    int inicol = image[sr][sc]; // Get the initial color of the starting pixel
    vector<vector<int>> ans = image; // Create a copy of the image to store the result

    int delRow[] = {-1, 0, 1, 0}; // Define the possible row offsets for adjacent pixels
    int delCol[] = {0, 1, 0, -1}; // Define the possible column offsets for adjacent pixels

    dfs(sr, sc, ans, image, inicol, delRow, delCol, color); // Start the flood fill from the specified pixel
    return ans; // Return the image with the filled region
}
