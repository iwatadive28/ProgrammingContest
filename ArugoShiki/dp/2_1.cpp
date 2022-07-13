#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){

    // 初期化    
    vector<vector<ll>> dp(4,vector<ll>(4,0));
    
    // 初期条件
    rep(i,4) cin >> dp[0][i];
    
    // dpループ
    for(ll i=1;i<4;++i){
       rep(j,4){
           dp[i][j] += dp[i-1][j];
           if (j-1>=0) dp[i][j] += dp[i-1][j-1];
           if (j+1<4 ) dp[i][j] += dp[i-1][j+1];
       }
    }
    
    // 出力
    /*
    rep(i,4){
        rep(j,4){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }
    */
    cout << dp[3][3] << endl;
    return 0;
}