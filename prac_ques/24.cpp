#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. LONG_INTEGER k
 *  4. INTEGER m
 */

vector<int> solve(int a, int b, long k, int m)
{
    int j = a, u = b;
    long q = k;
    long long int z = 1, e = 1, r = 1, t = 1;

    while (k != 0)
    {
        long long int x = 1, y = 1, a = j, b = u;
        if (k == 1)
        {
            x = j%m;
            y = u%m;
            k = 0;
        }
        else
        {

            for (int i = 2; i <= k; i *= 2)
            {
                x = ((a%m) * (a%m)) - ((b%m) * (b%m));
                y = 2 * (a%(m)) * (b%(m));
                a = x%m;
                b = y%m;
                k = q - i;
            }
        }
        z = (((x%m) * (e%m))%m) - (((r%m) * (y%m))%m);
        t = (((x%m) * (r%m))%m)  + (((e%m) * (y%m))%m);
        e = z%m;
        r = t%m;
    }
    vector<int> v;
    v.push_back(e );
    v.push_back(r );
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        long k = stol(first_multiple_input[2]);

        int m = stoi(first_multiple_input[3]);

        vector<int> result = solve(a, b, k, m);

        for (size_t i = 0; i < result.size(); i++)
        {
            fout << result[i];

            if (i != result.size() - 1)
            {
                fout << " ";
            }
        }

        fout << "\n";
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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
