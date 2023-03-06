#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/


int main(){
    int N;
    cin >> N;
    vector<int> A(N,0),C(4,0);
    rep(i,N) cin >> A[i];
    rep(i,N) C[A[i]]++;
    double dp[N+1][N+1][N+1]; 

    // rep(i,N+1) cout << C[i] << endl;
    rep(c3,N+1) rep(c2,N+1) rep(c1,N+1){
        int sm = c1+c2+c3;
        if(sm==0) continue;
        dp[c1][c2][c3] = 1.0 * N/sm;
        if(c1>0)         dp[c1][c2][c3] += dp[c1-1][c2  ][c3  ] * c1/sm;
        if(c2>0 && c1<N) dp[c1][c2][c3] += dp[c1+1][c2-1][c3  ] * c2/sm;
        if(c3>0 && c2<N) dp[c1][c2][c3] += dp[c1  ][c2+1][c3-1] * c3/sm;
        // printf("%d,%d,%d:",c1,c2,c3);
        // cout << dp[c1][c2][c3] << endl;
    }
    printf("%.10f\n",dp[C[1]][C[2]][C[3]]);
}