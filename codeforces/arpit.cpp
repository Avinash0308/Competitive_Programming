/*Given a hiking trail with varying terrain (represented as an array of integers, where each integer indicates the difficulty level of the terrain at that position), you are given a collection of boots, each with a maximum difficulty they can handle.
Your task is to determine the minimum number of times you need to change boots to complete the trail. Input: An array of integers representing the trail's difficulty levels. A list of boots, each with a maximum difficulty they can handle. Return the minimum number of boot changes required to reach the end of the trail.

Input:
 
A list of trails, where each number in the list represents the difficulty level of the terrain

A list of boots, where each number in the list represents the difficulty level of the terrain that boot can handle

Output: 

A single integer that represents the minimum number of boot changes required to reach the end of the trail, -1 if end of trail cant be reached.

Example:

Input: 
trail = [3, 2, 1]
boots = [4, 5, 3]
Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> trails, boots;
    int n, m;
    cin>>n;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        trails.push_back(x);
    }
    cin>>m;
    for(int i = 0; i<m; i++){
        int x;
        cin>>x;
        boots.push_back(x);
    }
    
}

int main(){
    solve();
    return 0;
}