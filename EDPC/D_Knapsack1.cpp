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
    int N,W;
    cin >> N >> W;
    vector<int> w(N),v(N);
    rep(i,N) cin >> w[i] >> v[i];
    
    // 初期化
    vector<vector<ll>> dp(N+1,vector<ll>(W+1,-1));
    dp[0][0] = 0;
    
    // 配るDP
    rep(i,N){
        rep(j,W){
            if(dp[i][j]==-1) continue;
            // i番目の品物を選ぶ場合
            if(j+w[i]<=W){
                chmax(dp[i+1][j+w[i]],dp[i][j]+v[i]);            
            }
            // 選ばない場合
            chmax(dp[i+1][j],dp[i][j]);
        }        
    }
    /*
    rep(i,N+1){
        rep(j,W+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    ll ans = 0;
    rep(j,W+1) chmax(ans,dp[N][j]);
    cout << ans << endl;
}
