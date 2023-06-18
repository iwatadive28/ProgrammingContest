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
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N,0),Y(N,0);
    rep(i,N) cin >> X[i] >> Y[i];

    vector<vector<ll>> dp(N+1,vector<ll>(2,0));
    dp[0][0] = 0;
    rep(i,N){
        rep(j,2){
            if(j==0 && X[i]==0){
                chmax(dp[i+1][j],dp[i][j]+Y[i]);  // 食べる場合
            }
            if(j==0 && X[i]==1){
                chmax(dp[i+1][j+1],dp[i][j]+Y[i]); // 食べる場合
            }
            if(j==1 && X[i]==0){
                chmax(dp[i+1][j-1],dp[i][j]+Y[i]); // 食べる場合
            }
            chmax(dp[i+1][j],dp[i][j]);           // 食べない場合
        }
    }

    ll ans = max(dp[N][0],dp[N][1]);
    cout << ans << endl;
}