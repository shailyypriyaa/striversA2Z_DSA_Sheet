#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    // Function to find the largest element in a vector of integers
    int largestElement(vector<int> &arr, int n)
    {
        // Initialize a variable 'max' to store the maximum element and set it to the first element of the vector.
        int max = arr[0];

        // Loop through the vector from the second element (index 1) to the last element (index n-1).
        for (int i = 1; i < n; i++)
        {
            // Check if the current element (arr[i]) is greater than the current maximum (max).
            if (max < arr[i])
                // If the current element is greater, update the maximum value to the current element.
                max = arr[i];
        }

        // Return the maximum element found in the vector.
        return max;
    }
};

