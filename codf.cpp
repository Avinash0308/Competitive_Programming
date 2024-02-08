#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int x, n;
        cin>>x>>n;
        if(x%n == 0){
            cout<<x/n<<endl;
        }
        else{
            int ans = 1;
            for(int i = x/n; i>=1; i--){
                int rem = x - ((x/i)*i);
                if(rem % i == 0){
                    ans = i;
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}