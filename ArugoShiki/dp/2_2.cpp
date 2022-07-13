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

    // 初期化    
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    
    // 初期条件
    rep(i,N) cin >> dp[0][i];
    
    // dpループ
    for(ll i=1;i<N;++i){
       rep(j,N){
           dp[i][j] += dp[i-1][j];
           if (j-1>=0) dp[i][j] += dp[i-1][j-1];
           if (j+1<N ) dp[i][j] += dp[i-1][j+1];
           dp[i][j] %= 100;
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
    cout << dp[N-1][N-1] << endl;
    return 0;
}