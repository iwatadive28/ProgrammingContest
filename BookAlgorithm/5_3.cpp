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

int main(){
    ll N;
    cin >> N;
    vector<ll> p(N);
    rep(i,N)  cin >> p[i];
    
    // 初期化 
    vector<vector<bool>> dp(N+1,vector<bool>(10001,false));
    dp[0][0] = true;
    
    // 配るDP
    rep(i,N){
        rep(j,10001){
            if(!dp[i][j]) continue;
            dp[i+1][j] = true;
            dp[i+1][j+p[i]] = true;
        }        
    }
    
    ll cnt = 0;
    rep(i,10001){
        if (dp[N][i]) ++cnt;
    }

    cout << cnt << endl;
    
    return 0;
}