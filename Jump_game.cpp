#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;  // If the array has 1 or 0 elements, no jump is needed
    if (arr[0] == 0) return -1;  // If the first element is 0, we cannot move anywhere

    int maxReach = arr[0];  // The maximum index we can reach so far
    int step = arr[0];      // The steps we can still take
    int jumps = 1;          // The number of jumps we have made

    for (int i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1) return jumps;

        // Update the maximum reachable index
        maxReach = max(maxReach, i + arr[i]);

        // Use a step to get to the current index
        step--;

        // If no steps are left
        if (step == 0) {
            // We must have used a jump
            jumps++;

            // Check if the current index/position is reachable
            if (i >= maxReach) return -1;

            // Reinitialize the steps to the amount
            // of steps to reach maxReach from position i
            step = maxReach - i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};  // Example input
    int result = minJumps(arr);
    if (result != -1) {
        cout << "Minimum number of jumps to reach the end is " << result << endl;
    } else {
        cout << "End of the array is not reachable." << endl;
    }
    return 0;
}
