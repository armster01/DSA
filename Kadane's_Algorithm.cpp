#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the largest sum contiguous subarray using Kadane's Algorithm
int maxSubArraySum(const vector<int>& arr) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (size_t i = 1; i < arr.size(); i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int max_sum = maxSubArraySum(arr);
    cout << "Largest sum contiguous subarray: " << max_sum << endl;

    return 0;
}
