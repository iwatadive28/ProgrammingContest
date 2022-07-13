#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(N+1),B(M+1),C(N+M+1);
    rep(i,N+1)   cin >> A[i];
    rep(i,N+M+1) cin >> C[i];

    for(int i=M;i>=0;--i){
        int kC = N+i; 
        // cout << "kC="<<kC<<endl;
        vector<int> tmp(kC+1,0);

        B[i] = C[kC]/A[N];
        rep(j,N+1){
            tmp[kC-j] = A[N-j]*B[i];
            // cout << tmp[kC-j] << "," ;
        }
        // cout << endl;
        // Next C
        
        rep(j,kC+1){
            C[j] = C[j]-tmp[j];
            //cout << C[j] << ",";
        }
        // cout << endl;
    }

    rep(i,M+1) cout <<B[i]<< " ";
    cout << endl;
}