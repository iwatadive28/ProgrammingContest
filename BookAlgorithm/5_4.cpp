#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
const ll INF = 1<<29;

int main(){
    ll N,W,K;
    cin >> N >> W >> K;
    vector<ll> a(N);
    rep(i,N)  cin >> a[i];
    
    // 初期化 
    vector<vector<ll>> dp(N+1,vector<ll>(W+1,INF));
    dp[0][0] = 0;
    
    // 配るDP
    rep(i,N){
        rep(j,W){
            if(dp[i][j]>N) continue;
            chmin(dp[i+1][j],dp[i][j]);
            if(j+a[i]<=W) chmin(dp[i+1][j+a[i]],dp[i][j]+1);
        }        
    }
    
    cout << (dp[N][W] <= K?"Yes":"No") << endl;
    
    return 0;
}