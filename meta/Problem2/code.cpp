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

        vector<int> v;
        ll i = 0;
        ll n = str.size();
        while(i<n){
            string temp = "";
            while(i<n && str[i] != ' '){
                temp += str[i];
                i++;
            }
            v.push_back(stoi(temp));
            i++;
        }
        string res = "Case #";
        res += to_string(ind);
        res += ": ";
        if(v[0] > v[1]){
            res += "YES";
        }
        else res += "NO";
        outputFile << res << endl;
        ind++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}