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
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<vector<ll>> dp(N+1,vector<ll>(2,-INF));
    dp[0][0] = 0;
    dp[0][1] = -INF;
    rep(i,N){
        dp[i+1][0] = max(dp[i][0] + A[i],dp[i][1] - A[i]);
        dp[i+1][1] = max(dp[i][0] - A[i],dp[i][1] + A[i]);
    }

    rep(i,N+1){
        cout << dp[i][0] << "," << dp[i][1]  << endl;        
    }

    ll ans = dp[N][0];
    cout << ans << endl;   
}
