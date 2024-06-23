#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n){
    int i = 0;
    while(i<n-1 && arr[i] < arr[i+1]) i++;
    if(i == n-1){
        cout<<"YES"<<endl;
        cout<<n<<" "<<n<<endl;
    }
    int pnt = i+1;
    while(i<n-1 && arr[i] > arr[i+1]) i++;
    if(pnt == 1 || arr[pnt-1] < arr[i]){
        if(i == n-1 || arr[pnt] < arr[i+1]){
            cout<<"YES"<<endl;
            cout<<pnt<<" "i+1<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        cout<<"NO"
    }

}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    solve(v,n);
    return 0;
}