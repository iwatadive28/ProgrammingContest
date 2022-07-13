#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
const ll INF = 1LL << 60;

int main(){
    int N,M;
    cin >> N >> M;
    int A[N];
    rep(i,N) cin >> A[i];

    // 初期化    
    vector<ll> dp(N+1,INF);
    
    // 初期条件
    dp[0] = 0;

    // dpループ
    for(int i=1;i<=N;i++){
        rep(j,M){
            if (i-j-1>=0){
                dp[i] = min(dp[i],dp[i-j-1]+(j+1)*A[i]);   
            }            
        }
    }
    // rep(i,N) cout << dp[i] << endl;
    
    // 出力
    cout << dp[N-1] << endl;
    return 0;
}