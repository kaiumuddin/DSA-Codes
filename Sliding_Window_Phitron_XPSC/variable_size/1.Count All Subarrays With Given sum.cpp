#include <iostream>
#include <vector>

using namespace std;

// Function to find all subarrays with a given sum
int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
  int l = 0;   // Left pointer of the window
  int r = 0;   // Right pointer of the window
  int s = 0;   // Current sum of elements within the window
  int ans = 0; // Counter for the number of subarrays with sum equal to k

  // Iterate over the array using the right pointer
  while (r < arr.size()) {
    s += arr[r]; // Include the current element in the sum

    // If the current sum exceeds the target sum k,
    // move the left pointer to reduce the window size
    while (s > k) {
      s -= arr[l]; // Exclude elements from the left side
      l++;         // Move the left pointer to the right
    }

    // If the current sum equals the target sum k,
    // increment the answer counter as we found a valid subarray
    if (s == k) {
      ans++;
    }

    r++; // Move the right pointer to expand the window
  }

  return ans; // Return the total number of subarrays found
}

int main() {
  // Example usage
  vector<int> arr = {2, 2, 4, 4, 5};
  int k = 8;                                         // Target sum
  int result = findAllSubarraysWithGivenSum(arr, k); // Call the function
  cout << "Number of subarrays with sum " << k << ": " << result
       << endl; // Print the result
  return 0;
}
