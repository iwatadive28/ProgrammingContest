#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
const ll INF = 1LL<<60;

int main(){
    int N;
    cin >> N;
    vector<vector<ll>> A(N,vector<ll>(N,0));
    rep(i,N){
        rep(j,N) {
            cin >> A[i][j];
        }
    }

    // 初期化    
    vector<vector<ll>> dp(N,vector<ll>(N,INF));
    
    // 初期条件
    dp[0][N-1] = A[0][N-1];

    // dpループ
    rep(i,N){
        for(int j=N-1;j>=0;--j){
            if (i>0)   dp[i][j] = min(dp[i][j], dp[i-1][j] + A[i][j]) ;                
            if (j+1<N) dp[i][j] = min(dp[i][j], dp[i][j+1] + A[i][j]) ;
        }
    }

    // 出力
    /*
    rep(i,N){
        rep(j,N){
            cout << dp[i][j] << ',';
        }
        cout << endl;
    }
    */
    cout << dp[N-1][0] << endl;
    return 0;
}