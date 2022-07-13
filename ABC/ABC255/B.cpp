#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i,K) cin >> A[i];
    vector<double> X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    double R = 0;
    rep(i,N){
        double rt = INF;
        rep(j,K){
            double Xa = X[A[j]-1];
            double Ya = Y[A[j]-1];
            rt = min(sqrt(pow(X[i]-Xa,2) +pow(Y[i]-Ya,2)),rt);
        }
        R = max(R,rt);
    }

    printf("%.7f\n",R);
}
