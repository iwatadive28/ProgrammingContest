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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353;
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    vector<vector<ll>>  dp(N,vector<ll>(10,0));
    dp[0][A[0]] = 1;

    rep(i,N-1){
        rep(j,10){
            if(dp[i][j]==0) continue;
            ll f = (A[i+1]+j)%10;
            dp[i+1][f] += dp[i][j];
            dp[i+1][f] %= MOD;
            ll g = (A[i+1]*j)%10;
            dp[i+1][g] += dp[i][j];
            dp[i+1][g] %= MOD;
        }
    }

    rep(j,10){
        cout << dp[N-1][j] << endl;
    }
}