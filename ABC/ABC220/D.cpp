#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> opF(vector<int> A){
    int x = A[0];
    int y = A[1];
    int N = A.length();
    for (int i=N-2, i>1, i--){
        A[i] = A[i+1];
    }
    A.erase(A.[N-1]);
    A[0] = (x+y)%10;
    return A;    
}


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    opF(A);
    rep(i,N){
        cout >> A[i] >> endl;
    }   
    //cout << res * N + cnt  << endl;    
}