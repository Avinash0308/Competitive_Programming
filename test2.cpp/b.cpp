#include<bits/stdc++.h>
using namespace std;

int minimumPockets(int N, int A[]){
    unordered_map<int,int> m;
    int ans = 0;
    for(int i = 0; i<N; i++){
        m[A[i]]++;
        ans = max(ans,m[A[i]]);
    }
    cout<<ans<<endl;
    return 0;
}

int main(){
    int A[] = {1, 2, 4, 3, 3, 2};
    minimumPockets(6,A);
    return 0;
}