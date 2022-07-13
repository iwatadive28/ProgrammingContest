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
    int D[M];
    rep(i,M) cin >> D[i];

    // 初期化    
    vector<bool> dp(N+1,false);
    
    // 初期条件
    dp[0] = true; 

    // dpループ
    for(int i=0;i<=N;i++){
       if (!dp[i]) continue;
       rep(j,M){
           dp[i+D[j]] = true;
       }
       if (dp[N]){
           break;
       }
    }
    // rep(i,N) cout << dp[i] << endl;
    
    // 出力
    cout << (dp[N] ? "Yes" : "No") << endl;
    return 0;
}