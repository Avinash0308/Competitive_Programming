#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if(n == 1) cout<<1<<endl<<1<<endl;
        else if(n<=3){
            cout<<2<<endl;
            for(ll i = 1; i<=n; i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if(n%2){
            cout<<n<<endl;
            cout<<2<<" "<<4<<" ";
            for(ll i = 5; i<=n-2; i++){
                cout<<i<<" ";
            }
            cout<<1<<" "<<3<<" "<<n-1<<<" "<<n<<endl;
        }
        else{
            
        }
    }
    return 0;
}