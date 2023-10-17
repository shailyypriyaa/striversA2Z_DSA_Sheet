// Include necessary headers.
#include<iostream>
#include<vector>
using namespace std;
// Function to rotate an array 'n' times.
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0]; // Store the first element in a temporary variable.

    // Shift each element in the array to the left by one position 'n' times.
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = temp; // Place the original first element at the end of the array.

    return arr; // Return the rotated array.
}
