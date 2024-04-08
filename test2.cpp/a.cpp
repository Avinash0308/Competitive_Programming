#include<bits/stdc++.h>
using namespace std;

int gameWinner(int N, int A[], int B[]){
    int alice = 0, bob = 0;
    for(int i = 0; i<N; i++){
        if(A[i] > B[i]){
            alice++;
        }
        else if(A[i] < B[i]){
            bob++;
        }
    }
    if(alice > bob){
        cout<<"A "<<alice<<endl;
    }
    else if(alice < bob){
        cout<<"B "<<bob<<endl;
    }
    else{
        cout<<"tied"<<endl;
    }
    return 0;
}

int main(){
    int A[] = {4,7,3,2,9};
    int B[] = {6,9,2,6,3};
    gameWinner(5,A,B);
    return 0;
}