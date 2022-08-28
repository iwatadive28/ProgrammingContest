#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353;
/*
*/
//
ll tmax = 100010;
int main(){
    int N;
    cin >> N;
    vector<vector<ll>> txa(tmax,vector<ll>(5,0));
    rep(i,N){
        ll t,x,a;
        cin>> t >> x >> a;
        txa[t][x] = a;
    }
    
    vector<vector<ll>> dp(tmax,vector<ll>(5,-INF));
    dp[0][0] = txa[0][0];
    
    // 貰うDP
    for(ll i=1;i<=100000;++i){
        rep(j,5){
            // 留まる
            chmax(dp[i][j],dp[i-1][j]);
            // 左
            if(j!=0)  chmax(dp[i][j],dp[i-1][j-1]);
            // 右
            if(j!=4)  chmax(dp[i][j],dp[i-1][j+1]);
        
            dp[i][j] += txa[i][j];           
        }        
    }

    ll ans = 0;
    rep(j,5) chmax(ans,dp[100000][j]);

    cout << ans << endl;
    
}
