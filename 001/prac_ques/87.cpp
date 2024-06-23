#include<bits/stdc++.h>
using namespace std;
int main(){
    string sumofString = "1,2_9,4-3,4^7,5,*7-,99,8,7,5,9,2,1->80"; 
    int sum = 0;
    for(int i = 0 ; i<sumofString.length() ; i++){
        if((int)sumofString[i] >= 48 && (int)sumofString[i] <= 57){
            int x = (int)sumofString[i]-48;
            while(i<sumofString.length()-1 && (int)sumofString[i+1] >= 48 && (int)sumofString[i+1] <= 57){
                x = x*10 + (int)sumofString[i+1]-48;
                i++;
            }
            sum+=x;
        }
    }
    cout<<sum<<endl;
    cout<<"Also the string is :: "<<sumofString<<endl;
}