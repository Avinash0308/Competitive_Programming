#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    map<int, int> m_map;
    m_map[5] = 5;
    auto it = m_map.upper_bound(10);
    if (it == m_map.begin())
    {
        cout << "TRUE" << endl;
    }
    else if (it == m_map.end())
    {
        cout << "FALSe" << endl;
        it--;
        cout<<(*it).second<<endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}