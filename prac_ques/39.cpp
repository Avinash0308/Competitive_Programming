#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string oddEven(string str)
    {
        // code here
        sort(str.begin(), str.end());
        vector<pair<char, int>> v;
        for (int i = 0; i < str.length(); i++)
        {
            pair<char, int> p;
            p.first = str[i];
            p.second = 1;
            while (str[i] == str[i + 1])
            {
                p.second++;
                i++;
            }
            v.push_back(p);
        }
        int  y = 0;
        for (int i = 0; i<v.size() ; i++){
            if((int)v[i].first%2 == v[i].second%2){
                y++;
            }
        }
        if(y%2 == 1){
            return "ODD";
        }
        return "EVEN";
    }
};
int main()
{

    return 0;
}