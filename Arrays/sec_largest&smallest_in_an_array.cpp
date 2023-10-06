#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 

// Function to find the second smallest element in a vector of integers
int secondSmallest(int n, vector<int> a)
{
    // If there are less than 2 elements in the vector, return -1 (as there's no second smallest element).
    if (n < 2)
        return -1;

    // Initialize two variables to keep track of the smallest and second smallest elements.
    int small = INT_MAX;
    int sec_small = INT_MAX;

    // Loop through the vector to find the smallest and second smallest elements.
    for (int i = 0; i < n; i++)
    {
        if (a[i] < small)
        {
            // If the current element is smaller than the smallest element, update the second smallest and smallest.
            sec_small = small;
            small = a[i];
        }
        else if (a[i] < sec_small && a[i] != small)
        {
            // If the current element is smaller than the second smallest and not equal to the smallest, update the second smallest.
            sec_small = a[i];
        }
    }

    // Return the second smallest element found in the vector.
    return sec_small;
}

// Function to find the second largest element in a vector of integers
int secondLargest(int n, vector<int> a)
{
    // If there are less than 2 elements in the vector, return -1 (as there's no second largest element).
    if (n < 2)
        return -1;

    // Initialize two variables to keep track of the largest and second largest elements.
    int large = INT_MIN;
    int sec_large = INT_MIN;

    // Loop through the vector to find the largest and second largest elements.
    for (int i = 0; i < n; i++)
    {
        if (a[i] > large)
        {
            // If the current element is larger than the largest element, update the second largest and largest.
            sec_large = large;
            large = a[i];
        }
        else if (a[i] > sec_large && a[i] != large)
        {
            // If the current element is larger than the second largest and not equal to the largest, update the second largest.
            sec_large = a[i];
        }
    }

    // Return the second largest element found in the vector.
    return sec_large;
}

// Function to get the second largest and second smallest elements and return them in a vector
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Create a vector to store the results.
    vector<int> v;

    // Find and add the second largest element to the result vector.
    int p = secondLargest(n, a);
    v.push_back(p);

    // Find and add the second smallest element to the result vector.
    int q = secondSmallest(n, a);
    v.push_back(q);

    // Return the result vector containing the second largest and second smallest elements.
    return v;
}
