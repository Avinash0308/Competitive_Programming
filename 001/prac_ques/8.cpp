#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    vector<pair <int,int>> me;
    
    pair<int,int> p;
    while(test--){
        
        long long int a;
        cin>>a;
        int b =1;
        if(a%2 == 1){
            cout<<"0"<<endl;
        }
        else{
           for(int i = 4; i<=a ; i+=2){
               if(a%i == 0){
                   b++;
                   vector<pair <int,int>> :: iterator it = find(me.begin() , me.end() , a/i);
                   if(it != me.end()){
                       b += it->second;
                       break;
                   }
               }
           }
           p.first = a;
           p.second = b;
           me.push_back(p);
           cout<<b<<endl;
           
        }
    }
}