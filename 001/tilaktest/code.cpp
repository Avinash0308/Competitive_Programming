#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0; i<n; i++){
        int val;
        cin>>val;
        if(val >= 0){
            v.push_back(val);
        }
    }
    int s = v.size();
    int ind = ((s+1)/2) - 1;
    cout<<v[ind]<<endl;
    return 0;
}