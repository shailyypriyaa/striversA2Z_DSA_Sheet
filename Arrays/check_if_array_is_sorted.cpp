#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = 0; // Initialize pivot with a default value
        int n = nums.size();
        
        // Find the pivot point where the array is rotated (if any)
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i + 1; // Update pivot to the index of the next element
                break; // Exit the loop once the pivot is found
            }
        }
        
        vector<int> ans;
        
        // Create a rotated version of the original array
        for (int i = pivot; i < n; i++) {
            ans.push_back(nums[i]);
        }
        for (int i = 0; i < pivot; i++) {
            ans.push_back(nums[i]);
        }

        // Check if the rotated array is sorted in non-decreasing order
        for (int i = 0; i < n - 1; i++) {
            if (ans[i] > ans[i + 1]) {
                return false; // If not sorted, return false
            }
        }
        return true; // If sorted, return true
    }
};
