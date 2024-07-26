#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<pair<ll,ll>> v(n);
        for(ll i = 0; i<n; i++){
            cin>>v[i].first;
        }
        for(ll i = 0; i<n; i++){
            cin>>v[i].second;
        }
        sort(v.begin(),v.end());
        ll num = m/v[0].first;
        num = min(num,v[0].second);
        ll best = num*v[0].first;
        for(int i = 1; i<n; i++){
            num = m/v[i].first;
            num = min(num,v[i].second);
            if(v[i].first == v[i-1].first+1){
                ll val = v[i].second*v[i].first + v[i-1].second*v[i-1].first;
                if(val <= m){
                    best = max(best,val);
                }
                else{
                    ll first = v[i].first * num;
                    ll cur_value, rem_cur, rem_prev, done = 0;
                    if(m == first){
                        best = max(best,m);
                        done = 1;
                    }
                    else if(num + 1 <= v[i].second){
                        cur_value = v[i].first*(num+1);
                        rem_cur = v[i].second - num -1;
                        rem_prev = v[i-1].second;
                    }
                    else{
                        cur_value = v[i].second * v[i].first;
                        ll spacewa = m - cur_value;
                        ll countwa = spacewa/v[i-1].first;
                        cur_value += (countwa+1)*v[i-1].first;
                        rem_cur = 0;
                        rem_prev = v[i-1].second - countwa - 1;
                    }
                    if(!done){
                        ll jada = cur_value - m;
                        ll used_cur = v[i].second - rem_cur;
                        if(used_cur >= jada && rem_prev >= jada){
                            best = max(best,m);
                        }
                        else{
                            if(v[i].first * v[i].second >= m){
                                best = max(best,v[i].first*num);
                            }
                            else{
                                cur_value -= v[i-1].first;
                                best = max(best,cur_value);
                            }
                        }
                    }
                }
            }
            else{
                best = max(best,num*v[i].first);
            }
        }
        cout<<best<<endl;
    }
    return 0;
}