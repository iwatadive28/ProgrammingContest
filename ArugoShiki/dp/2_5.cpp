#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int main(){
    int N;
    cin >> N;
    string S[N];
    rep(i,N) cin >> S[i];

    // 初期化    
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    
    // 初期条件
    dp[0][0] = 1;

    // dpループ
    rep(i,N){
        rep(j,N){
            if (S[i][j] != '#'){
                if (i>0) dp[i][j] += dp[i-1][j];
                if (j>0) dp[i][j] += dp[i][j-1];
            }
        }
    }

    // 出力
    /*
    rep(i,N){
        rep(j,3){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }
    */
    cout << dp[N-1][N-1] << endl;
    return 0;
}