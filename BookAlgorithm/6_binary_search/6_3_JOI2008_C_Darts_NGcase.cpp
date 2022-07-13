#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
const int INF = 20000000;
 
int main(){
     // 入力
    ll N,M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i,N) cin >> P[i];
    
    sort(P.begin(),P.end());
    
    // 初期化 
    vector<vector<bool>> dp(5,vector<bool>(M+1,false));
    dp[0][0] = true;
    
    // (N+1)*(N+1)通りの選択肢があるので、全部試す。
    rep(i,4){
        rep(j,M){
            if(!dp[i][j])continue;
            // 当たらなかった場合
            dp[i+1][j] = true;
            rep(k,N){
               if (j+P[k]<=M){
                   dp[i+1][j+P[k]] = true;
               } 
            }    
        }
    }

    ll ans = -1;
    rep(i,M){
        if(!dp[4][i]) continue;
        ans = i;
    }
    cout << ans << endl;
    
    return 0;
}