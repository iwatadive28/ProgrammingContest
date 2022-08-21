#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
// 
int main(){
    // 頂点数, 変数, 始点
    int N,M;
    cin >> N >> M;

    // dp 配列(INF で初期化)
    vector<vector<ll>> dp(N,vector<ll>(N,INF));
    // dp 初期条件
    rep(e,M){
        int a,b;
        ll  w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    rep(v,N) dp[v][v] = 0;

    // dp 遷移（フロイド・ワーシャル法）
    rep(k,N){
        rep(i,N){
            rep(j,N){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    
    // 結果出力
    // dp[v][v] < 0 なら負閉路が存在する
    bool exist_negative_cycle = false;
    rep(v,N){
        if (dp[v][v] < 0) exist_negative_cycle = true;
    }
    if(exist_negative_cycle){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        rep(i,N){
            rep(j,N){
                if(j)                cout << " ";
                if(dp[i][j] < INF/2) cout << dp[i][j];
                else                 cout << "INF";
            }
            cout << endl;
        }
    }
}
