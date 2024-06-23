#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> left(n);
    vector<int> right(n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += (s[i]-'0');
        left[i] = sum;
    }
    sum = 0;
    for(int j = n-1; j>=0; j--){
        sum += s[j]-'0';
        right[j] = sum;
    }
    int ans = 0;
    for(int i= 0; i<n; i++){
        for(int j = i; j<n; j++){
            if((j-i)%2){
                int mid = (j+i)/2;
                int l_sum = left[mid] - ((i>0)?left[i-1]:0);
                int r_sum = right[mid+1] - ((j<n-1)?right[j+1]:0);
                if(l_sum == r_sum){
                    ans = max(ans,j-i+1);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}