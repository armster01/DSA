#include <iostream>
#include <vector>
using namespace std;

vector<int> findSubarrayWithGivenSum(const vector<int>& nums, int targetSum) {
    int start = 0, end = 0, currentSum = 0;
    
    while (end < nums.size()) {
        // Add the current element to the currentSum
        currentSum += nums[end];
        
        // While currentSum is greater than targetSum, subtract the start element
        while (currentSum > targetSum && start <= end) {
            currentSum -= nums[start];
            start++;
        }
        
        // Check if the currentSum is equal to the targetSum
        if (currentSum == targetSum) {
            return {start, end};
        }
        
        // Move to the next element
        end++;
    }
    
    // Return an empty vector if no subarray is found
    return {};
}

int main() {
    vector<int> nums = {1, 4, 20, 3, 10, 5};
    int targetSum = 33;
    
    vector<int> result = findSubarrayWithGivenSum(nums, targetSum);
    
    if (!result.empty()) {
        cout << "Subarray with given sum found from index " << result[0] << " to " << result[1] << endl;
    } else {
        cout << "No subarray with given sum found" << endl;
    }
    
    return 0;
}
