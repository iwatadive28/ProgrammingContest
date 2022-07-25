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
    int N,M;
    cin >> N >> M;
    vector<int> X(N),CY(N+1,0);
    rep(i,N) cin >> X[i];
    rep(i,M){
        int c,y;
        cin >> c >> y;
        CY[c] = y;
    }    
    // 初期化
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,-1));
    dp[0][0] = 0;
    
    // 配るDP
    rep(i,N){
        rep(j,N){
            if(dp[i][j]==-1) continue;
            // 表の場合
            dp[i+1][j+1] = dp[i][j]+X[i]+CY[j+1];
            // 裏の場合
            dp[i+1][0] = max(dp[i+1][0],dp[i][j]);
        }
    }

    /*
    rep(i,N+1){
        rep(j,N+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    
    ll ans = -1;
    rep(j,N+1) ans = max(ans,dp[N][j]);
    cout << ans << endl;
    
}
