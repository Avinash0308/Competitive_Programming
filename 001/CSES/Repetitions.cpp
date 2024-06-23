#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string s;
    cin>>s;
    int len = 0;
    int n = s.size();
    for(int i = 0; i<n; i++){
        int cur = 1;
        while(i<n-1 && s[i] == s[i+1]){
            cur++;
            i++;
        }
        len = max(len,cur);
    }
    cout<<len<<endl;
    return 0;
}