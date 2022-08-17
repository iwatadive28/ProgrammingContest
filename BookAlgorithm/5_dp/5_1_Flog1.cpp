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
    int N;
    cin >> N;
    vector<int> h(N);
    rep(i,N) cin >> h[i];

    // 初期化
    vector<ll> dp(N,INF);
    dp[0] = 0;

    // 配るDP
    rep(i,N-1){
        // i+1
        dp[i+1] = min(dp[i]+abs(h[i+1]-h[i]),dp[i+1]);
        // i+2
        if(i+2<N){
            dp[i+2] = min(dp[i]+abs(h[i+2]-h[i]),dp[i+2]);
        }        
    }
    cout << dp[N-1] << endl;
}
