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

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> a(N,vector<ll>(3));
    rep(i,N){
        rep(j,3){
            cin >> a[i][j];
        }
    }

    // 初期化 
    vector<vector<ll>> dp(N+1,vector<ll>(3,0));
    
    // 配るDP
    rep(i,N){
        rep(j,3){ // i日前の状態
            rep(k,3){ // i+1日前の状態
                if (j==k) continue;
                dp[i+1][k] = max(dp[i+1][k],dp[i][j]+a[i][k]);
                // chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }
    
    ll ans = 0;
    rep(i,3){
        ans = max(ans,dp[N][i]);
        // chmax(ans,dp[N][i]);
    }

    cout << ans << endl;
    
    return 0;
}