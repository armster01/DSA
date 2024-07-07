#include <iostream>
#include <vector>
using namespace std;

int maxSum(int arr[], int n) {
    // Compute arr_sum and curr_val
    int arr_sum = 0;
    int curr_val = 0;
    for (int i = 0; i < n; i++) {
        arr_sum += arr[i];
        curr_val += i * arr[i];
    }

    // Initialize max_val
    int max_val = curr_val;

    // Compute next_val for each rotation and update max_val
    int next_val = 0;
    for (int rotation = 1; rotation < n; rotation++) {
        next_val = curr_val + arr_sum - n * arr[n - rotation];
        if (next_val > max_val) {
            max_val = next_val;
        }
        curr_val = next_val;
    }

    return max_val;
}

int main() {
    int arr[] = {8, 3, 1, 2}; // Example input array
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum of i*arr[i] among all rotations: " << maxSum(arr, n) << endl;
    return 0;
}
