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
    string S,T;
    cin >> S>> T;
    vector<ll> a(N),m(N);
    
    
    // 初期化 
    vector<vector<int>> dp(N+1,vector<int>(W+1,INF));
    dp[0][0] = 0;
    
    // 配るDP
    rep(i,N){
        rep(j,W){
            // 足さない場合
            if(dp[i][j] < INF)  chmin(dp[i+1][j],0);
            //
            if(dp[i+1][j] < m[i]){
                if(j+a[i]<=W) chmin(dp[i+1][j+a[i]],dp[i+1][j]+1);    
            }            
        }        
    }
    
    cout << (dp[N][W]<INF?"Yes":"No") << endl;
    
    return 0;
}