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
    ll N,W;
    cin >> N >> W;
    vector<ll> w(N),v(N);
    rep(i,N)  cin >> w[i] >> v[i];
    
    // 初期化 
    vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));
    
    // 配るDP
    rep(i,N){
        rep(j,W){
            // 品物を選ばない場合
            chmax(dp[i+1][j],dp[i][j]);
            // 品物を選ぶ場合
            if(j+w[i]<=W) chmax(dp[i+1][j+w[i]],dp[i][j]+v[i]);
        }        
    }
    /*
    rep(i,N+1){
        rep(j,W+1) cout << dp[i][j] << " ";
        cout << endl;
    }*/
    cout << dp[N][W] << endl;
}