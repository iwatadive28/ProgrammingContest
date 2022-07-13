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
    for(ll i=1;i<N+1;++i){
        rep(j,M+1){
            // 選択しない場合
            if(dp[i-1][j]) dp[i][j] = dp[i-1][j]; 

            // 選択する場合
            if(j-A[i-1]>=0){
                if(dp[i-1][j-A[i-1]]) dp[i][j] = true;  
            } 
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