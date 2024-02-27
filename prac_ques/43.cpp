#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
       set<int> s;
        for(int i= 0; i<n ; i++){
            s.insert(a[i]);
        }
        for(int i= 0; i<m ; i++){
            s.insert(b[i]);
        }
      
        int x = s.size();
        return x;
    }
};
int main(){
    Solution s;
    int a[] = { 34,5, 3};
    int b[] = {34, 5,2};
    cout<< s.doUnion(a , 3, b, 3);
return 0;
}