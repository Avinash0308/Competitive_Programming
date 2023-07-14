#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        vector<int> v;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '{')
            {
                v.push_back(1);
            }
            if (x[i] == '[')
            {
                v.push_back(2);
            }
            if (x[i] == '(')
            {
                v.push_back(3);
            }
            if (x[i] == '}')
            {
                v.push_back(4);
            }
            if (x[i] == ']')
            {
                v.push_back(5);
            }
            if (x[i] == ')')
            {
                v.push_back(6);
            }
        }
    }
};