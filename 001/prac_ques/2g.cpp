#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int test;
    cin >> test;
    while (test--){
        unsigned long long int num;
        cin >> num;
        unsigned long long int b = 1;
        while (b){
            if ((int)log2(b) + 1 >= (int)log2(num / b) + 1){
                cout << (num - b) + 1 << endl;
                b = 0;
            }
            else{
                b ++;
            }
        }
    }
    return 0;
}