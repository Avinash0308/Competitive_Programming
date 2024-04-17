#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string n;
        cin>>n;
        string y;
        cin>>y;
        ll size = n.size();
        ll ind = 0;
        while(ind < size && n[ind] == y[ind]) ind++;
        if(ind == size){
            cout<<n<<endl;
            cout<<y<<endl;
        }
        else{
            if(n[ind] < y[ind]){
                char c = n[ind];
                n[ind] = y[ind];
                y[ind] = c;
            }
            ind++;
            while(ind<size){
                if(n[ind] > y[ind]){
                    char c = n[ind];
                    n[ind] = y[ind];
                    y[ind] = c;
                }
                ind++;
            }
            cout<<n<<endl;
            cout<<y<<endl;
        }
    }
    return 0;
}