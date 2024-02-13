#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> create(long long int val)
{
    int zero = 0;
    while (val && val % 10 == 0)
    {
        zero++;
        val /= 10;
    }
    int rem = 0;
    while (val)
    {
        rem++;
        val /= 10;
    }
    return {zero, rem};
}
bool comp(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
        return a.first > b.first;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        vector<long long int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<pair<long long int, long long int>> x(n);
        for (int i = 0; i < n; i++)
        {
            x[i] = create(v[i]);
        }
        sort(x.begin(), x.end(), comp);
        vector<long long int> some;
        int first = 0;
        while(first < n){
            int val = x[first].second;
            first++;
            if(first < n){
                val += (x[first].first + x[first].second);
                first++;
            }
            some.push_back(val);
        }
        long long int total = 0;
        for(auto ind:some){
            total += ind;
        }
        if(total > m){
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Anna"<<endl;
        }
    }
    return 0;
}