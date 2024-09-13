#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ordered_set s, o;
    int ans = 0;
    for(int i = n-1; i>=0; i--){
        s.insert(v[i]);
        ans += s.order_of_key(v[i]);
    }
    int res = 0;
    for(int i = 0; i<n; i++){
        o.insert(v[i]);
        res += o.order_of_key(v[i]);
    }
    cout<<min(res,ans)<<endl;
    return 0;
}