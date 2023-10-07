#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // Initialize variables to store the starting and ending positions
        int startingPosition = -1, endingPosition = -1;

        // Get the size of the input array
        int n = nums.size();

        // Iterate through the array to find the starting position
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                startingPosition = i;
                break;  // Exit the loop as soon as the first occurrence is found
            }
        }

        // Iterate through the array in reverse to find the ending position
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == target) {
                endingPosition = i;
                break;  // Exit the loop as soon as the last occurrence is found
            }
        }

        // Return a vector containing the starting and ending positions
        return {startingPosition, endingPosition};
    }
};
