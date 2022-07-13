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
    int N,A,B;
    cin >> N >> A >> B;
    vector<ll> X(N);

    rep(i,N) cin >> X[i];
    
    // 初期化    
    vector<vector<bool>> dp(N+1,vector<bool>(A+1,false));
    
    // 初期条件
    dp[0][0] = true;

    // dpループ 配るdp
    rep(i,N){
        rep(j,A+1){ // 
            if (!dp[i][j]) continue;
            
            // アイテムiを選ぶ場合
            dp[i+1][(j+X[i]) % A] = true; 

            // アイテムiを入れない
            dp[i+1][j] = true;
        }
    }

    // 出力
    /*
    rep(i,N+1){
        rep(j,A+1){
            cout << dp[i][j] << ',';
            // printf("% 3d,",(int)dp[i][j]);
        }
        cout << endl;
    }
    */
    cout << (dp[N][B] ? "Yes" : "No") << endl;
    return 0;
}