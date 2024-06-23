#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &a){
    // hcf(a,b)*lcm(a,b) = a*b, means multiple of hcf and lcm of two numbers is equal to multiple of given number itself
    // so we are required to find pairs such that there multiple is present in array.
    int n = a.size();
    unordered_map<int,int> mp; // unordered_map to store the elements of array.
    for(auto i:a){
        mp[i]++;
    }
    int ans = 0;// answer counter
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(mp.count(a[i]*a[j]) != 0){ // if a[i]*a[j] is present in map then increase answer counter by 2.
                ans += 2; // because (i,j) & (j,i) need to be counted separately.
            }
        }
    }
    return ans; // return the answer
    // Time Complexity = (n^2);
    // Space Complexity = (n);
    // I don't think this solution will work becuase tc is n^2, not able to think of any better solution right now.
}
int main(){
    return 0;
}