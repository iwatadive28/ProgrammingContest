#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    int S;
    cin >> S;
    
    ll ans = 0;
    vector<ll> dp(S+1,0);

    for(int i=3;i<=S;++i){
        ll x = 0;
        for(int j=3;j<=i;++j){
            x += dp[i-j];
            x %= MOD;
        }        
        dp[i] = x+1;
        dp[i] %= MOD;
    }
    // rep(i,S+1) {cout << dp[i] << " ";} cout << endl;    
    cout << dp[S] << endl;
}
