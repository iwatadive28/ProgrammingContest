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
    vector<ll> dp(N,0);
    
    // 初期条件
    dp[0] = 1;
    dp[1] = 2;
    
    // dpループ
    for(int i=2;i<N;i++){
        dp[i] = dp[i-1]+dp[i-2];   
    }
    // rep(i,N) cout << dp[i] << endl;
    
    // 出力
    cout << dp[N-1] << endl;
    return 0;
}