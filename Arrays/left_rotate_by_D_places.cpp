#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Helper function to reverse a portion of the 'nums' array between 'start' and 'end'.
    void reverse(vector<int>& nums, int start, int end) {
        while (start <= end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    // Main function to rotate the 'nums' array by 'k' positions to the right.
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the array.

        // Normalize 'k' to avoid unnecessary rotations if 'k' is greater than 'n'.
        k = k % n;

        // Reverse three portions of the array to achieve the rotation.
        // 1. Reverse the first part from the beginning to n-k-1.
        reverse(nums, 0, n - k - 1);
        // 2. Reverse the second part from n-k to n-1.
        reverse(nums, n - k, n - 1);
        // 3. Reverse the entire array to complete the rotation.
        reverse(nums, 0, n - 1);
    }
};
