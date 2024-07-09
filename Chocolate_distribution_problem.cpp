#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findMinDiff(const vector<int>& arr, int n, int m) {
    // If there are no chocolates or students
    if (m == 0 || n == 0)
        return 0;
    
    // Sort the given packets
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    // Number of students cannot be more than number of packets
    if (n < m)
        return -1;
    
    // Find the minimum difference
    int minDiff = INT_MAX;
    
    // Find the subarray of size m such that difference between the last (maximum) and first (minimum) elements is minimized
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = sortedArr[i + m - 1] - sortedArr[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

int main() {
    vector<int> arr = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; // Number of students
    int n = arr.size();
    cout << "Minimum difference is " << findMinDiff(arr, n, m) << endl;
    return 0;
}
