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
    vector<vector<int>> a(N,vector<int>(3));
    rep(i,N){
        rep(j,3) cin >> a[i][j];
    }
    
    // 初期化
    vector<vector<ll>> dp(N+1,vector<ll>(3,-1));
    rep(j,3) dp[0][j] = 0;
    
    // 配るDP
    rep(i,N){
        rep(j,3){
            chmax(dp[i+1][(j+1)%3],dp[i][j]+a[i][(j+1)%3]);
            chmax(dp[i+1][(j+2)%3],dp[i][j]+a[i][(j+2)%3]);
        }        
    }

    ll ans = 0;
    rep(j,3) chmax(ans,dp[N][j]);
    cout << ans << endl;
}
