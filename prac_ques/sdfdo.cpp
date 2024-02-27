#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int> a, vector<int> b){
    if(a[0] < b[0]) return true;
    if(a[0] > b[0]) return false;
    else return a[1] >= b[1];
}
int search(vector<vector<int>> &v,int val){
    int l = 0, h = v.size() - 1;
    while(l<=h){
        int mid = (l+h)/2;
        if(v[mid][0] >= val){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return l;33
}
int search2(vector<vector<int>> &v, int val){
    int low = 0, high = v.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid][0] <= val){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
int main(){

    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        v[i] = {a,b,i};
    }    
    sort(v.begin(),v.end(),comp);
    int q;
    cin>>q;

    for(int i = 0; i<q; i++){
        int low , high;
        cin>>low>>high;
        int l = search(v,low);
        int h = search2(v,high);
        cout<<(h-l+1)<<" mobiles are available"<<endl;

        for(int j = l; j<n; j++){
            cout<<"Price "<<v[j][0]<<" Speed "<<v[j][1]<<endl;
        }
    }
return 0;

}