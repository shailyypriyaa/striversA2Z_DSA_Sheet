#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Function to perform binary search for a target element in a sorted array 'nums'.
    int search(vector<int> &nums, int target) 
    {
        // Initialize two pointers, 'low' and 'high', representing the search range.
        int low = 0;
        int high = nums.size() - 1;
        
        // Perform binary search as long as 'low' is less than or equal to 'high'.
        while (low <= high)
        {
            // Calculate the middle index of the current search range.
            int mid = low + (high - low) / 2;
            
            // Check if the middle element is equal to the target.
            if (nums[mid] == target)
                return mid; // If found, return the index of the target element.
            else if (nums[mid] > target)
                high = mid - 1; // If the middle element is greater than the target, narrow the search to the left half.
            else
                low = mid + 1;  // If the middle element is less than the target, narrow the search to the right half.
        }
        
        // If the target element is not found in the array, return -1 to indicate that it doesn't exist.
        return -1;
    }
};
