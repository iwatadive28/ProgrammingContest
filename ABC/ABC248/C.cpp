#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<vector<ll>> dp(N+1,vector<ll>(K+1,0));
    dp[0][0] = 1;
    
    rep(i,N){
        rep(j,K){
            if(dp[i][j]!=0){
                for(int k=1;k<=M;++k){
                    if(j+k<=K) dp[i+1][j+k] = (dp[i+1][j+k]+dp[i][j])%MOD;
                }
            }
        }
    }
    /*
    rep(i,N+1){
        cout << i << ":";
        rep(j,K+1) cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    ll ans = 0;
    rep(i,K+1) ans = (ans + dp[N][i])%MOD;
    cout << ans << endl;
}