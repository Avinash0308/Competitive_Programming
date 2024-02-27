#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

int primeCount(long n)
{
    long long int m = n / 2;
    int flag = 0;
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (n == 1)
    {
        return 0;
    }
    else if (flag == 0)
    {
        return 1;
    }
    else
    {
        if(n>=2 && n<6){
            return 1;
        }
        if(n>=6 && n<30){
            return 2;
        }
        if(n>=30 && n<210){
            return 3;
        }
        if(n>=210 && n<2310){
            return 4;
        }
        if(n>=2310 && n<30030){
            return 5;
        }
        if(n>= 30030&& n<510510){
            return 6;
        }
        if(n>=510510 && n<9699690){
            return 7;
        }
        if(n>=9699690 && n<223092870){
            return 8;
        }
        if(n>= 223092870&& n<6469693230){
            return 9;
        }
        if(n>= 6469693230&& n<200560490130){
            return 10;
        }
        if(n>=200560490130 && n<7420738134810){
            return 11;
        }
        if(n>=7420738134810 && n<304250263527210){
            return 12;
        }
        if(n>=304250263527210 && n<1.308276133167003e+16){
            return 13;
        }
        if(n>= 1.308276133167003e+16){
            return 14;
        }
        
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
