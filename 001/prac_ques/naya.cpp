#include<bits/stdc++.h>
using namespace std;
// Program to convert Roman
// Numerals to Numbers

// This function returns value
// of a Roman symbol
string intToRoman(int num)
{
    // storing roman values of digits from 0-9
    // when placed at different places
    string m[] = { "", "M", "MM", "MMM" };
    string c[] = { "",  "C",  "CC",  "CCC",  "CD",
                   "D", "DC", "DCC", "DCCC", "CM" };
    string x[] = { "",  "X",  "XX",  "XXX",  "XL",
                   "L", "LX", "LXX", "LXXX", "XC" };
    string i[] = { "",  "I",  "II",  "III",  "IV",f
                   "V", "VI", "VII", "VIII", "IX" };
 
    // Converting to roman
    string thousands = m[num / 1000];
    string hundreds = c[(num % 1000) / 100];
    string tens = x[(num % 100) / 10];
    string ones = i[num % 10];
 
    string ans = thousands + hundreds + tens + ones;
 
    return ans;
}
int value(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;

	return -1;
}

// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
	// Initialize result
	int res = 0;

	// Traverse given input
	for (int i = 0; i < str.length(); i++) {
		// Getting value of symbol s[i]
		int s1 = value(str[i]);

		if (i + 1 < str.length()) {
			// Getting value of symbol s[i+1]
			int s2 = value(str[i + 1]);

			// Comparing both values
			if (s1 >= s2) {
				// Value of current symbol
				// is greater or equal to
				// the next symbol
				res = res + s1;
			}
			else {
				// Value of current symbol is
				// less than the next symbol
				res = res + s2 - s1;
				i++;
			}
		}
		else {
			res = res + s1;
		}
	}
	return res;
}


vector<string> sortRoman(vector<string> &names){
    int n = names.size();
    vector<pair<string,int>> v(n);
    for(int i = 0; i<n; i++){
        int j = 0;
        string cur;
        while(j<names[i].size() && names[i][j] != ' '){
            cur.push_back(names[i][j]);
            j++;
        }
        j++;
        string num;
        while(j<names[i].size()){
            num.push_back(names[i][j]);
            j++;
        }
        int val = romanToDecimal(num);
        v[i] = {cur,val};
    }
    sort(v.begin(),v.end());
    vector<string> ans(n);
    for(int i = 0; i<n; i++){
        ans[i] += v[i].first;
        ans[i].push_back(' ');
        string st = intToRoman(v[i].second);
        ans[i] += st;
    }
    return ans;
}
int main(){
    vector<string> cur = {"Louis IX","Louis VIII"};
    vector<string> ans = sortRoman(cur);
    for(int i= 0; i<cur.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}