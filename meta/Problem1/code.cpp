#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ifstream inputFile("1.txt");
    ofstream outputFile;
    outputFile.open("1_o.txt",ios_base::app);
    string str;
    getline(inputFile,str);
    ll t = stoi(str);
    ll ind = 1;
    while(ind<=t){
        getline(inputFile,str);   
        ll n = str.size();
        ll i = 0;
        ll s = 0, d = 0, k = 0;
        while(i<n && str[i] != ' '){
            s = s*10 + (str[i] - '0');
            i++;
        }
        i++;
        while(i<n && str[i] !=  ' '){
            d = d*10 + (str[i] - '0');
            i++;
        }
        i++;
        while(i<n){
            k = k*10 + (str[i]-'0');
            i++;
        }
        ll bun = (s+d)*2;
        ll cheese = s + d*2;
        ll patties = s + d*2;
        if(k + 1 <= bun && k <= cheese && k <= patties){
            string res = "Case #";
            res += to_string(ind);
            res += ": YES";
            outputFile<<res<<endl;
        }
        else{
            string res = "Case #";
            res += to_string(ind);
            res += ": NO";
            outputFile<<res<<endl;
        }
        ind++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}