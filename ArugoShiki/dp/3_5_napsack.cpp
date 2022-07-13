#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
const ll INF = 1LL<<60;
//
int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> W(N);

    rep(i,N) cin >> W[i];
    
    // 初期化    
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,INF));
    
    // 初期条件
    dp[0][0] = 0;

    // dpループ もらうdp
    for(ll i=0;i<N;++i){ // アイテム
        rep(j,M+1){ // 重さ
            // アイテムiを入れる場合
            if (j+W[i]<=M) dp[i+1][j+W[i]] = min(dp[i+1][j+W[i]],dp[i][j]+1);

            // アイテムiを入れない
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
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
    cout << (dp[N][M]==INF ? -1 : dp[N][M]) << endl;
    return 0;
}