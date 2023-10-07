#include<iostream>
#include<vector>
using namespace std;
// Function to find the floor of a given element 'x' in a sorted array 'a'
int findFloor(vector<int> &a, int n, int x)
{
    // Initialize low and high indices for binary search
    int low = 0, high = n - 1;

    // Initialize the answer variable with a default value of -1
    int ans = -1;

    while (low <= high)
    {
        // Calculate the middle index
        int mid = (low + high) / 2;

        // If the middle element is less than or equal to 'x',
        // update the answer and search in the right half
        if (a[mid] <= x)
        {
            ans = a[mid];
            low = mid + 1;
        }
        else
        {
            // If the middle element is greater than 'x', search in the left half
            high = mid - 1;
        }
    }
    return ans;
}

// Function to find the ceiling of a given element 'x' in a sorted array 'a'
int findCeil(vector<int> &a, int n, int x)
{
    // Initialize low and high indices for binary search
    int low = 0, high = n - 1;

    // Initialize the answer variable with a default value of -1
    int ans = -1;

    while (low <= high)
    {
        // Calculate the middle index
        int mid = (low + high) / 2;

        // If the middle element is greater than or equal to 'x',
        // update the answer and search in the left half
        if (a[mid] >= x)
        {
            ans = a[mid];
            high = mid - 1;
        }
        else
        {
            // If the middle element is less than 'x', search in the right half
            low = mid + 1;
        }
    }
    return ans;
}

// Function to get the floor and ceiling of a given element 'x' in a sorted array 'a'
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    // Find the floor and ceiling using the previously defined functions
    int f = findFloor(a, n, x);
    int c = findCeil(a, n, x);

    // Return a pair containing the floor and ceiling values
    return make_pair(f, c);
}
