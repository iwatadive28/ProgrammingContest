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
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    // 初期化    
    vector<vector<bool>> dp(N+1,vector<bool>(M+1,false));
    
    // 初期条件
    dp[0][0] = true;

    // dpループ
    rep(i,N){
        rep(j,M){
            // Falseの場合
            if(!dp[i][j]) continue; 

            // 次のアイテムを選択しない場合
            dp[i+1][j] = true;
            
            // 次のアイテムを選択する場合
            if (j+A[i] <= M) dp[i+1][j+A[i]] = true;
        }
    }

    // 出力
    /*
    rep(i,N+1){
        rep(j,M+1){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }
    */
    cout << (dp[N][M] ? "Yes":"No") << endl;
    return 0;
}