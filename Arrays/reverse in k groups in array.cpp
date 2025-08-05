#include <iostream>
#include <vector>
using namespace std;

// Function to reverse every sub-array formed by
// consecutive k elements
void reverseInGroups(vector<int>& arr, int k) {
    int n = arr.size();  // Get the size of the array

    for (int i = 0; i < n; i += k)
    {
        int left = i;

        // to handle case when k is not multiple of n
        int right = min(i + k - 1, n - 1);

        // reverse the sub-array [left, right]
        while (left < right)
            swap(arr[left++], arr[right--]);

    }
}

// Driver code
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8}; // Input array
    int k = 3; // Size of sub-arrays to be reversed

    reverseInGroups(arr, k); // Call function to reverse in groups

    // Print modified array
    for (int num : arr)
        cout << num << " ";

    return 0;
}
