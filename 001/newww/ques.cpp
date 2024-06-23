#include<bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        while(i<n || j<m){
            while(i<n && version1[i] == '0') i++;
            while(j<m && version2[j] == '0') j++;
            if(i == n && j == m) return 0;
            if(i == n && version2[j] == '.'){
                cout<<version2[j]<<endl;
                j++;
                continue;
            } 
            else if(i == n) return -1;
            if(j == m && version1[i] == '.'){
                cout<<version1[i]<<endl;
                i++;
                continue;
            }
            else if(j == m) return 1;
            if(version1[i] == '.' && version2[j] == '.'){
                cout<<version1[i]<<" "<<version2[j]<<endl;
                i++;
                j++;
                continue;
            }
            if(version1[i] == '.') return -1;
            if(version2[j] == '.') return 1;
            if(version1[i] == version2[j]){
                cout<<version1[i]<<" "<<version2[j]<<endl;
                i++;
                j++;
                continue;
            }
            else if(version1[i] > version2[j]) return 1;
            else return -1;
        }
        return 0;
    }

int main(){
    cout<<compareVersion("1.0","1.0.0")<<endl;
    return 0;
}