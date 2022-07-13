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
    ll A[N];
    rep(i,N) cin >> A[i];
    
    // 初期化    
    vector<ll> dp(N,0);
    
    // 初期条件
    dp[0] = 0;
    dp[1] = A[1];
    
    // dpループ
    for(int i=2;i<N;i++){
        // 操作1
        dp[i] = min(dp[i-2] +2*A[i],
                    dp[i-1] +A[i] );    
    }
    // rep(i,N) cout << dp[i] << endl;
    
    // 出力
    cout << dp[N-1] << endl;
    return 0;
}