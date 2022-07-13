#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N-1),B(N-1);

    rep(i,N-1) cin >> A[i];
    rep(i,N-1) cin >> B[i];
    
    // 初期化    
    vector<vector<ll>> dp(N,vector<ll>(M,-1));
    
    // 初期条件
    dp[0][0] = 0;

    // dpループ 配るdp
    rep(i,N-1){
        rep(j,M){
            // Falseの場合
            if(dp[i][j]==-1) continue; 

            // 1 つ下のマスに移動する
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            
            // (あるならば) 1 つ下Aiつ右のマスに移動し、Biポイントを得る
            if (j+A[i] < M) dp[i+1][j+A[i]] = max(dp[i+1][j+A[i]] ,dp[i][j]+B[i]);
        }
    }

    // 出力
    /*
    rep(i,N){
        rep(j,M){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }
    */
    cout << dp[N-1][M-1] << endl;
    return 0;
}