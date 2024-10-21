#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll maxy = 1e7+1;
    vector<ll> v(maxy);
    for(ll i = 2; i*i <= maxy; i++){
        if(v[i]) continue;
        for(ll j = i*i; j<=maxy; j+=i){
            v[j] = 1;
        }
    }
    vector<ll> answ(maxy);
    answ[5] = 2;
    for(ll i = 6; i<=maxy; i++){
        if(v[i]){
            answ[i] = answ[i-1];
        }
        else{
            if(v[i-2] == 0){
                answ[i] = answ[i-1]+1;
            }
            else{
                answ[i] = answ[i-1];
            }
        }
    }
    ifstream inputFile("in.txt");
    ofstream outputFile;
    outputFile.open("out.txt", ios_base::app);
    string str;
    getline(inputFile, str);
    ll t = stol(str);
    ll ind = 1;
    while (ind <= t)
    {
        getline(inputFile, str);

        ll indi = stol(str);
        string result = to_string(answ[indi]);

        string res = "Case #";
        res += to_string(ind);
        res += ": ";
        res += result;
        outputFile << res << endl;
        ind++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}