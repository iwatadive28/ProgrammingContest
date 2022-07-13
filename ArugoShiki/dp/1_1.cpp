#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
const ll INF = 1LL << 60;
int N,X,Y;

int main(){
    cin >> N >> X >> Y;
    int A[N];
    A[0] = X;
    A[1] = Y;

    for(int i=2;i<N;++i){
        A[i] = (A[i-1]+A[i-2])%100;
    }
    cout << A[N-1] << endl;
    return 0;
}