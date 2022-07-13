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
    int N;
    cin >> N;
    vector<ll> W(N);

    int M = 0;
    rep(i,N) {
        cin >> W[i];
        M += W[i];
    }
    // 初期化
    vector<vector<bool>> dp(N+1,vector<bool>(M+1,false));
    
    // 初期条件
    dp[0][0] = true;

    // dpループ 配るdp
    rep(i,N){
        rep(j,M){ // 箱に入っている重さの総和の差
            if(!dp[i][j]) continue;

            // 総和が大きい方のグループに追加する場合
            dp[i+1][j+W[i]] = true;
            // 総和が小さい方のグループに追加する場合
            dp[i+1][abs(j-W[i])] = true; 
        }
    }

    // 出力
    /*
    rep(i,N+1){
        rep(j,M+1){
            cout << dp[i][j] << ',';
            //printf("% 3d,",(int)dp[i][j]);
        }
        cout << endl;
    }
    */
    int res = 0;
    while (!dp[N][res]) ++res;
    cout << res << endl;

    return 0;
}