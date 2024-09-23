class Solution {
public:
    // Function to generate the kth row of Pascal's Triangle
    vector<int> getRow(int k) {
        vector<int> row(k + 1, 1); // Initialize the row with 1s

        for (int i = 1; i <= k; i++) {
            // Update the row from right to left
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row; // Return the kth row
    }
};
