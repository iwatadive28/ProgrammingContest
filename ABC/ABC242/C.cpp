#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
#define mod 998244353;
/*
*/
//

int main(){
    int N;
    cin >> N;

    // DP初期化
    vector<vector<ull>> dp(N,vector<ull>(9,0));
    rep(i,9) dp[0][i] = 1;

    // 配るDP
    rep(i,N-1){
        rep(j,9) dp[i][j] %= mod;
        rep(j,9){
            if (j-1>=0) dp[i+1][j-1] += dp[i][j];
            dp[i+1][j] += dp[i][j];
            if (j+1<9) dp[i+1][j+1] += dp[i][j];
        }
    }

    ull ans = 0;
    rep(i,9){
        ans += dp[N-1][i];
        ans %= mod;
    }    
    cout << ans << endl;
}