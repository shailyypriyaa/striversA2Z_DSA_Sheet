#include<iostream>
#include<vector>
using namespace std;
int lowerBound(vector<int> arr, int n, int x) 
{
	// Initialize low and high indices for binary search
	int low = 0, high = n - 1;

	// Initialize the answer variable with a default value of n
	int ans = n;

	// Perform binary search
	while (low <= high)
	{
		// Calculate the middle index
		int mid = (low + high) / 2;

		// If the middle element is greater than or equal to x
		if (arr[mid] >= x)
		{
			// Update the answer to the current middle index
			ans = mid;

			// Continue searching in the left half by adjusting the 'high' pointer
			high = mid - 1;
		}
		else
		{
			// If the middle element is less than x, search in the right half
			// by adjusting the 'low' pointer
			low = mid + 1;
		}
	}

	// Return the index of the first element greater than or equal to x
	return ans;
}
