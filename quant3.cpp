#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string solution(int N, vector<string> S)
{
    vector<string> v;
    int ind = 0;
    v.push_back("home");
    for (int i = 0; i < N; i++)
    {
        int x = v.size();
        if (S[i] == "back")
        {
            if (ind != 0)
            {
                ind--;
            }
        }
        else if (S[i] == "forward")
        {
            if ((ind + 1) != x)
            {
                ind++;
            }
        }
        else
        {
            while (x != (ind + 1))
            {
                v.pop_back();
                x--;
            }
            v.push_back(S[i]);
            ind++;
        }
    }
    string ans;
    for (int i = 0; i < v.size(); i++)
    {
        ans.push_back('/');
        ans += v[i];
    }
    return ans;
}
int main()
{
    vector<string> str = {"forward","forward","forward"};
    cout<<solution(3,str)<<endl;
    return 0;
}