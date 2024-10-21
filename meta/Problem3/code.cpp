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
    while (ind <= t)
    {
        getline(inputFile, str);
        ll n = stoi(str);
        vector<pair<double,double>> v(n);
        for(ll i = 0; i<n; i++){
            getline(inputFile, str);
            ll j = 0; 
            double val = 0;
            while(str[j] != ' '){
                val = val*10 + str[j]-'0';
                j++;
            }
            v[i].first = val;
            val = 0;
            j++;
            while(j != str.size()){
                val = val*10 + str[j]-'0';
                j++;
            }
            v[i].second = val;
        }
        double x = 0, y = 1e9+7;
        ll pos = 1;
        for(ll i = 0; i<n && pos; i++){
            double miny = (i+1)/v[i].second;
            double maxy = (v[i].first == 0)?1e9+7:((i+1)/v[i].first);
            if(miny > y || maxy < x){
                pos = 0;
                break;
            }
            x = max(x,miny);
            y = min(y,maxy);
        }

        string result;
        if(pos){
            result = to_string(x);
        }
        else{
            result = "-1";
        }

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