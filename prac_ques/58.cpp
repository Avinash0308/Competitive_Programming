#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> flav;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            flav.push_back(x);
        }
        int q;
        cin >> q;
        vector<pair<int, int>> que;
        for (int i = 0; i < q; i++)
        {
            pair<int, int> p;
            int a, b;
            cin >> a;
            cin >> b;
            p.first = a;
            p.second = b;
            que.push_back(p);
            vector<int> in;
            vector<int> val;
            vector<int> flav2 = flav;
            for(int j = 0; j<n ; j++){
                if(flav[j] % que[i].first == 0){
                    in.push_back(j);
                    val.push_back(flav[j]);
                }
            }
            sort(val.begin(),val.end());
            for(int j = 0; j<in.size() ; j++){
                flav2[in[j]] = val[val.size() - 1 - j];
            }
            int ant = 0;
            for(int j = 0; i<que[j].second ; j++){
                ant+=flav2[j];
            }
            cout<<ant<<endl;
        }
    }
    return 0;
}