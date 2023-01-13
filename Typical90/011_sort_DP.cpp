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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
/*
//*/
int main(){
    ll N;
    cin >> N;
    vector<ll> D(N),C(N),S(N);
    rep(i,N) cin >> D[i] >> C[i] >> S[i];

    // 締め切り D[i] 順
    vector<tuple<ll,ll,ll>> tp;
    rep(i,N) tp.push_back({D[i],C[i],S[i]});
    sort(tp.begin(),tp.end());
    rep(i,N){
        D[i] = get<0>(tp[i]);
        C[i] = get<1>(tp[i]);
        S[i] = get<2>(tp[i]);
    }
    
    // DP
    vector<vector<ll>> dp(N+1,vector<ll>(5001,0));
    
    for(ll i=0;i<N;++i){
        for(ll j=0;j<=5000;++j){
            // cout << i << "," << j << endl;
            // 仕事iを捨てる場合
            chmax(dp[i+1][j],dp[i][j]);
            
            // 仕事iをやる場合
            if(j+C[i]<=D[i]){
                chmax(dp[i+1][j+C[i]],dp[i][j]+S[i]);
            }
            //*/
        }
    }

    ll ans = 0;
    rep(j,5001) chmax(ans,dp[N][j]);
    cout << ans << endl;
    //*/
}