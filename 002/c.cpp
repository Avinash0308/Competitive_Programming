#include<bits/stdc++.h>
using namespace std;

int solution(vector<string> &A){
    int a = 0, b = 0, c = 0, d= 0;
    for(auto i:A){
        if(i == "RR") a++;
        else if(i == "GG") b++;
        else if(i == "RG") c++;
        else d++;
    }
    int ans = 0;
    if(c == 0 && d == 0) return max(a,b);
    if(c == 0 || d == 0){
        return a + b + 1;
    }
    if(c == d) return a + b + c + d;
    return min(c,d)*2 + 1 + a + b;
}

int main(){
    vector<string> s = {"RG","RG","RG"};
    cout<<solution(s)<<endl;
    return 0;
}