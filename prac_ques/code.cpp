#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;

int StringChallenge(string str) {
  
  // code goes here 
  int n = str.size();
  int start  = 0;
  for(int i = 0; i<n-1; i++){
    while(i<n-1 && str[i] == str[i+1]) {i++;}
    if(i != n-1){
      int len = i-start+1;
      start = i+1;
      if(len%2){
        int v[3] = {0,0,0};
        v[str[i]-'a']++;
        v[str[i+1]-'a']++;
        for(int z = 0; z<3; z++){
          if(!v[z]) str[i+1] = (char)(z+97);
        }
      }
    }
  }
  return n-start;

}
int main(){
    return 0;
}