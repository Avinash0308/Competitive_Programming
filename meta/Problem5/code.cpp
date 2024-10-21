#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ifstream inputFile("in.txt");
    ofstream outputFile;
    outputFile.open("out.txt", ios_base::app);
    string str;
    getline(inputFile, str);
    ll t = stoi(str);
    ll ind = 1;
    ll mod = 998244353;
    while (ind <= t)
    {
        getline(inputFile, str);
        ll w = 0, g = 0, l = 0;
        ll i = 0;
        ll n = str.size();
        while(str[i] != ' '){
            w = w*10 + str[i]-'0';
            i++;
        }
        i++;
        while(str[i] != ' '){
            g = g*10 + str[i]-'0';
            i++;
        }
        i++;
        while(i != n){
            l = l*10 + str[i]-'0';
            i++;
        }
        
        string res = "Case #";
        res += to_string(ind);
        res += ": ";
        // res += result;
        outputFile << res << endl;
        ind++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}