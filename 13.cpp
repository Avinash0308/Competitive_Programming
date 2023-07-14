#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    int num;
	    cin>>num;
	    string s;
	    cin>>s;
	    int a = 0;
        int x = 1;
	    for(int i = 0; i<s.length() ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                a = 0;
            }
            else{
                a++;
                if(a == 4){
                    cout<<"NO"<<endl;
                    x = 0;
                    break;
                }
            }
        }
        if(x){
            cout<<"YES"<<endl;
        }
	}
	return 0;
}
