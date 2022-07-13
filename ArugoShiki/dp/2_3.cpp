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

    vector<vector<ll>> A(N,vector<ll>(3,0));
    rep(i,N){
        rep(j,3){
            cin >> A[i][j];
        }
    }

    // 初期化    
    vector<vector<ll>> dp(N,vector<ll>(3,0));
    
    // 初期条件
    rep(j,3) dp[0][j] = A[0][j];
    
    // dpループ
    for(ll i=1;i<N;++i){
       rep(j,3){           
           int n1 = (j+1)%3;
           int n2 = (j+2)%3;
           dp[i][j] = A[i][j] + max(dp[i-1][n1],dp[i-1][n2]);           
       }
    }

    // 出力
    ll ans = max(max(dp[N-1][0], dp[N-1][1]),dp[N-1][2]);
    /*
    rep(i,N){
        rep(j,3){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}