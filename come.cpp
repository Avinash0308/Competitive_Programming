#include <iostream>
#include <vector>

using namespace std;

// Function to check if an array is a good array
bool isGoodArray(const vector<int>& array, int m) {
    for (int k = 1; k <= m; ++k) {
        if (array[k] != 20) {
            return false;
        }
    }
    return true;
}

// Function to count the number of ways to merge rows to form a good array
int countGoodArrays(const vector<vector<int>>& A, const vector<int>& goodArray) {
    int n = A.size(); // Number of rows
    int m = goodArray.size() - 1; // Size of the array B

    int count = 0;

    // Iterate through all pairs of rows
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Merge rows i and j to create array B
            vector<int> B(m + 1, 0);
            for (int k = 1; k <= m; ++k) {
                B[k] = max(A[i][k], A[j][k]);
            }

            // Check if the merged array is a good array
            if (isGoodArray(B, m)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    // Input the 2D array A
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the size of the array (m): ";
    cin >> m;

    vector<vector<int>> A(n, vector<int>(m + 1, 0));

    cout << "Enter the elements of the 2D array A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
        }
    }

    // Input the special array (good array)
    vector<int> goodArray(m + 1, 0);

    cout << "Enter the elements of the special array:" << endl;
    for (int k = 1; k <= m; ++k) {
        cin >> goodArray[k];
    }

    // Count the number of ways to merge rows to form a good array
    int result = countGoodArrays(A, goodArray);

    // Output the result
    cout << "Number of altered pours: " << result << endl;

    return 0;
}
