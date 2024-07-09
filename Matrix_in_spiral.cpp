#include <iostream>
#include <vector>
using namespace std;

void printSpiralOrder(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top boundary
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        ++top;

        // Traverse from top to bottom along the right boundary
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[right][i] << " ";
        }
        --right;

        // Traverse from right to left along the bottom boundary
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            --bottom;
        }

        // Traverse from bottom to top along the left boundary
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            ++left;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Spiral order of the given matrix is: ";
    printSpiralOrder(matrix);

    return 0;
}
