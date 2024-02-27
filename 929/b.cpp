#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0 ;i<n; i++){
            cin>>v[i];
        }
        int sum = 0;
        vector<int> m(3);
        for(int i = 0; i<n; i++){
            sum += v[i];
            m[v[i]%3]++;
        }
        if(sum%3){
            if(sum%3 == 1){
                if(m[1] != 0){
                    cout<<1<<endl;
                }
                else{
                    cout<<2<<endl;
                }
            }
            else{
                if(m[2] != 0){
                    cout<<1<<endl;
                }
                else{
                    cout<<1<<endl;
                }
            }
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}