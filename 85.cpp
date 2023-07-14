#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        string ress;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack<char> f;
                f.push('(');
                string ran;
                string res;
                while (!f.empty() && i < s.length() - 1)
                {
                    if (s[i + 1] == ')')
                    {
                        f.pop();
                    }
                    if (f.empty())
                    {
                        res = infixToPostfix(ran);
                        ress += res;
                    }
                    else
                    {
                        ran.push_back(s[i + 1]);
                        if (s[i + 1] == '(')
                        {
                            f.push('(');
                        }
                    }
                    i++;
                }
            }
            else if (s[i] == '^')
            {
                st.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '^'))
                {
                    ress.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!st.empty())
                {
                    ress.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            else
            {
                ress.push_back(s[i]);
            }
        }
        while (!st.empty())
        {
            ress.push_back(st.top());
            st.pop();
        }
        return ress;
    }
};
int main()
{
    Solution trial;
    cout<<trial.infixToPostfix("a*b-c*(d+e)-((f+i)-(j*k))")<<endl;
    return 0;
}