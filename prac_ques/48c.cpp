#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int a = 0;
        for(long long  i = 0; i<N ;i++){
            long long ar[N-i];
            copy(arr+i,arr+N,ar);
            sort(ar,ar+N-i);
            long long j = 0;
            while(ar[j]!=arr[i]){
                j++;
            }
            a+=j;
        }
        return a;
    }
};
int main(){
    
return 0;
}