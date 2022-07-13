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
    vector<ll> A(N-1);
    rep(i,N-1) cin >> A[i];
    
    // 初期化    
    vector<vector<bool>> dp(N,vector<bool>(M,false));
    
    // 初期条件
    dp[0][0] = true;

    // dpループ
    for(ll i=1;i<N;++i){
        rep(j,M){
            if (dp[i-1][j]) dp[i][j] = true;
            if (j-A[i-1]>=0){
                if (dp[i-1][j-A[i-1]]) dp[i][j] = true;
            }
        }
    }

    // 出力
    int ans = 0;
    rep(j,M){
        if (dp[N-1][j]) ans++;
    }
    /*
    rep(i,N){
        rep(j,M){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}