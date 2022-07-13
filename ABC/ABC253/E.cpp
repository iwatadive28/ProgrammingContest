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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353;
/*
*/
//
int main(){
        
    vector<vector<int>> G;
    int N,M,K;

    cin >> N >> M >> K;

    vector<vector<ll>> dp(N,vector<ll>(M,0));
    rep(j,M) dp[0][j] = 1;
    
    vector<ll> g(M,0);
    rep(j,M) g[j+1]=(dp[0][j+1]+dp[0][j])%MOD;

    rep(i,N-1){
        rep(j,M){
            if (j-K>=0) dp[i+1][j] = (dp[i+1][j] + g[j-K])%MOD;
            if (j+K<M)  dp[i+1][j] = (dp[i+1][j] + g[j+K])%MOD;
            if (K==0)  (dp[i+1][j] = dp[i][j])%=MOD;
        }
        rep(j,M) g[j+1]=(dp[i][j+1]+dp[i][j])%MOD;
    }
    
    rep(i,N){
        rep(j,M) cout << dp[i][j] << " ";
        cout << endl;
    }

    ll ans = 0;
    rep(j,M){
        ans = (ans + dp[N-1][j])%MOD;
    }

    cout << ans << endl;

}
