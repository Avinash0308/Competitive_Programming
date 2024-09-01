#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(n%2 == 0){
            unordered_map<char,ll> mp, cp;
            ll a = 0, b = 0;
            for(ll i = 0; i<n; i+=2){
                mp[s[i]]++;
                a = max(a,mp[s[i]]);
            }
            for(ll i = 1; i<n; i+=2){
                cp[s[i]]++;
                b = max(b,cp[s[i]]);
            }
            cout<<n-a-b<<endl;
        }
        else if(n == 1) cout<<1<<endl;
        else{
            unordered_map<char,ll> e, f, g, h;
            for(ll i = n-1; i>=0; i-=2){
                g[s[i]]++;
            }
            for(ll i = n-2; i>=0; i-=2){
                h[s[i]]++;
            }
            ll ans = n;
            unordered_map<char,ll> xy, yz;
            for(ll i = 0; i<n; i++){
                ll maxi = 0, maxy = 0;
                if(i%2){
                    h[s[i]]--;
                    if(i-1 >= 0){
                        for(auto z:e){
                            xy[z.first] += z.second;
                        }
                    }
                    if(i+2<n){
                        for(auto z: h){
                            xy[z.first] += z.second;
                        }
                    }
                    if(i-2 >=0){
                        for(auto z:f){
                            yz[z.first] += z.second;
                        }
                    }
                    if(i+1<n){
                        for(auto z:g){
                            yz[z.first] += z.second;
                        }
                    }
                    f[s[i]]++;
                }
                else{
                    g[s[i]]--;
                    if(i-1 >= 0){
                        for(auto z:f){
                            xy[z.first] += z.second;
                        }
                    }
                    if(i+2<n){
                        for(auto z:g){
                            xy[z.first] += z.second;
                        }
                    }
                    if(i-2 >=0){
                        for(auto z:e){
                            yz[z.first] += z.second;
                        }
                    }
                    if(i+1<n){
                        for(auto z:h){
                            yz[z.first] += z.second;
                        }
                    }
                    e[s[i]]++;
                }
                for(auto z:xy){
                    maxi = max(maxi,z.second);
                    //cout<<z.first<<" "<<z.second<<endl;
                }
                for(auto z:yz){
                    maxy = max(maxy,z.second);
                    //cout<<z.first<<" "<<z.second<<endl;
                }
                // cout<<maxy<<" "<<maxi<<endl;
                xy.clear();
                yz.clear();
                ans = min(ans,n-maxy-maxi);
            }
            cout<<ans<<endl;
            e.clear();
            f.clear();
            g.clear();
            h.clear();
        }
    }
    return 0;
}