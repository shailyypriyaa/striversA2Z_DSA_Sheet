#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        // Initialize low to the beginning of the array and high to the size of the array
        int low = 0;
        int high = nums.size();
        
        // Declare the mid variable
        int mid;
        
        // Check if the target is greater than the last element of the array
        // If it is, return the position after the last element
        if (target > nums[high - 1])
            return high;

        // Perform binary search
        while (low <= high)
        {
            // Calculate the middle index
            mid = (low + high) / 2;
            
            // If the middle element is equal to the target, return its position
            if (nums[mid] == target)
                return mid;

            // If the target is less than the middle element, search in the left half
            if (target < nums[mid])
                high = mid - 1;
            // If the target is greater than the middle element, search in the right half
            else
                low = mid + 1;
        }
        
        // If the target is not found, return the position where it should be inserted
        return low;
    }
};
