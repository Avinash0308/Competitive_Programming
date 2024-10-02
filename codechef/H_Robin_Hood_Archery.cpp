// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n, q;
//         cin>>n>>q;
//         vector<ll> v(n);
//         for(ll i = 0; i<n; i++){
//             cin>>v[i];
//         }
//         vector<vector<ll>> query(q,vector<ll>(2));
//         for(ll i = 0; i<q; i++){
//             ll a, b;
//             cin>>a>>b;
//             a -= 1;
//             b -= 1;
//             query[i][0] = a;
//             query[i][1] = b;
//         }
//         vector<ll> x(n);
//         ll cur1 = 0;
//         for(ll i = 0; i<n; i++){
//             cur1 ^= v[i];
//             x[i] = cur1;
//         }
//         for(ll i = 0; i<q; i++){
//             ll a = query[i][0];
//             ll b = query[i][1];
//             if(a > b) swap(a,b);
//             ll cur = x[b];
//             if(a > 0) cur ^= x[a-1];
//             if(cur == 0) cout<<"YES"<<endl;
//             else cout<<"NO"<<endl;
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <set>
 
using namespace std;
 
 
void work(){
    int n,q;
    cin >> n >> q;
    vector<unsigned long long> v(n);
    for (auto &c : v) cin >> c;
 
    random_device rd; 
    mt19937_64 gen(rd());
    map<unsigned long long, unsigned long long> mapping;
    set<unsigned long long> used = {0};
 
    for (auto &c : v){
        unsigned long long random;
        if (mapping.count(c) == 0){
            do{
                random = gen();
            }while (used.find(c) != used.end());
            used.insert(random);
            mapping[c] = random;
        }else{
            random = mapping[c];
        }
        c = random;
    }
 
    vector<unsigned long long> xor_pref(n+1);
 
    for (int i=0;i<n;i++) xor_pref[i+1] = xor_pref[i] ^ v[i];
    
    for (int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << ((xor_pref[r]^xor_pref[l-1])?"NO\n":"YES\n");
    }
}
 
int main(){
 
    int t;
    cin >> t;
    while (t--) work();
 
    return 0;
}