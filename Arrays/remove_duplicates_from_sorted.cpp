#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1; // Initialize a count to keep track of unique elements

        for (int i = 1; i < nums.size(); i++) {
            // Check if the current element is different from the previous element
            if (nums[i] != nums[i - 1]) {
                // If it's different, update the array by moving the unique element to the next position
                nums[count] = nums[i];
                count++; // Increment the count to indicate the presence of a unique element
            }
        }
        return count; // Return the count, which represents the number of unique elements in the modified array
    }
};
