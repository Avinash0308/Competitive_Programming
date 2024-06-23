#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    stack<int> st;
    for(int i = 0;i <n; i++){
        if(v[i] < 0){
            while(!st.empty() && st.top() > 0 && abs(v[i]) > st.top()) st.pop();
            if(!st.empty() && st.top() == abs(v[i])){
                st.pop();
            }
            else if(st.empty() || (!st.empty() && st.top() < 0))st.push(v[i]);
        }
        else{
            st.push(v[i]);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}