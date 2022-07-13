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
    vector<ll> W(N),V(N);

    rep(i,N) cin >> W[i];
    rep(i,N) cin >> V[i];
    
    // 初期化    
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,0));
    
    // 初期条件
    dp[0][0] = 0;

    // dpループ 配るdp
    for(ll i=0;i<N;++i){
        rep(j,M+1){
            // アイテムiを入れない
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            
            // アイテムiを入れる場合
            if (j+W[i]<=M) dp[i+1][j+W[i]] = max(dp[i+1][j+W[i]] ,dp[i][j]+V[i]);
        }
    }

    // 出力
    /*
    rep(i,N+1){
        rep(j,M+1){
            printf("% 3d,",(int)dp[i][j]);
        }
        cout << endl;
    }
    */
    cout << dp[N][M] << endl;
    return 0;
}