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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,-INF));
    dp[0][0] = 0;
    rep(i,N){
        rep(j,M+1){
            chmax(dp[i+1][j],dp[i][j]);
            if(j<M) chmax(dp[i+1][j+1],dp[i][j]+A[i]*(j+1));
        }
    }
    /*
    rep(i,N+1) {
        rep(j,M+1) cout << dp[i][j] << " ";
        cout << endl;
    }
    */

    cout << dp[N][M] << endl;
}
