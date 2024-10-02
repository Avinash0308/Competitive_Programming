#include<bits/stdc++.h>
using namespace std;
int solve(int ind, int N, string &S, vector<int> &A, unordered_map<int,vector<int>> &str, vector<vector<int>> &cnt, unordered_map<int,int> &mp){
    if(ind == N-1) return A[N-1];
    if(mp.count(ind) != 0) return mp[ind];
    int ans = solve(ind+1,N,S,A,str,cnt,mp);
    vector<int> prev(26,0);
    if(ind > 0) prev = cnt[ind-1];
    for(int i = 0; i<26; i++){
        int last = prev[i];
        if(last == str[i].size()) continue;
        int next = str[i][last];
        if(next != ind){
            ans = min(ans,solve(next,N,S,A,str,cnt,mp));
        }
    }
    return mp[ind] = ans + A[ind];
}
int get_ans(int N, string S, vector<int> A){
    unordered_map<int,int> mp;
    unordered_map<int,vector<int>> str;
    for(int i = 0; i<N; i++){
        str[S[i]-'a'].push_back(i);
    }
    vector<vector<int>> cnt(N);
    vector<int> cur(26);
    for(int i = 0; i<N; i++){
        cur[S[i]-'a']++;
        cnt[i] = cur;
    }
    return solve(0,N,S,A,str,cnt,mp);
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> A(n);
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    cout<<get_ans(n,s,A)<<endl;
    return 0;
}