#include <iostream>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--){
        long long int sizeA ;
        cin>>sizeA;
        unsigned long long int B[sizeA];
        long long int sum = 0 ;
        for(int i = 0; i<sizeA ; i++){
            cin>>B[i];
            sum+=B[i];
        }
        long long int A[sizeA];
        for(int i = 0; i<sizeA ; i++){
            A[i] = sum/4 - ((sum - 2*B[i])/2);
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
	// your code goes here
	return 0;
}