#include<bits/stdc++.h>
using namespace std;
long long int lastStoneWeight(vector<long long int>& stones) {
    priority_queue<long long int> p;
    for (long long int i : stones) {
        p.push(stone);
    }
    while (p.size() > 1) {
        long long int a = p.top();
        p.pop();
        long long int b = p.top();
        p.pop();
        if(a != b){
            p.push(abs(a-b));
        }
    }
    if(p.size()) return p.top();
    else return 0;
}

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int result = lastStoneWeight(stones);
    cout << result << endl; // Output: 1
    return 0;
}
