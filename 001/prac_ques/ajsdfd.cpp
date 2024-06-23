#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getMaximumSum(vector<int>& no_adjacent, vector<int>& one_adjacent, vector<int>& both_adjacent) {
    int n = no_adjacent.size();
    vector<long long> dp_no(n + 1, 0);
    vector<long long> dp_one(n + 1, 0);
    vector<long long> dp_both(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        dp_no[i] = max(dp_no[i - 1], max(dp_one[i - 1], dp_both[i - 1])) + no_adjacent[i - 1];
        dp_one[i] = max(dp_no[i - 1], dp_both[i - 1]) + one_adjacent[i - 1];
        dp_both[i] = max(dp_no[i - 1], max(dp_one[i - 1], dp_both[i - 1])) + both_adjacent[i - 1];
    }

    return max(dp_no[n], max(dp_one[n], dp_both[n]));
}

int main() {
    // Example usage:
    vector<int> no_adjacent = {1,6};
    vector<int> one_adjacent = {2,3};
    vector<int> both_adjacent = {3,2};

    long long result = getMaximumSum(no_adjacent, one_adjacent, both_adjacent);

    cout << "Maximum efficiency sum: " << result << endl;

    return 0;
}
