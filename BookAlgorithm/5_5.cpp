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
const ll INF = 1<<29;

int main(){
    ll N,W;
    cin >> N >> W;
    vector<ll> a(N);
    rep(i,N)  cin >> a[i];
    
    // 初期化 
    vector<vector<bool>> dp(N+1,vector<bool>(W+1,false));
    dp[0][0] = false;
    
    // 配るDP
    rep(i,N){
        rep(j,W){
            if(dp[i][j])  dp[i+1][j] = dp[i][j];
            if(dp[i+1][j]){
                if(j+a[i]<=W) dp[i+1][j+a[i]] = true;    
            }            
        }        
    }
    
    cout << (dp[N][W]?"Yes":"No") << endl;
    
    return 0;
}