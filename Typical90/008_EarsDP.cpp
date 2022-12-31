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
const string atcoder = "atcoder";
int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    vector<vector<ll>> dp(N+1,vector<ll>(8,0));
    dp[0][0] = 1;
    // 配るDP
    rep(i,N){
        rep(j,8){
            dp[i+1][j] += dp[i][j];
            if(j==8) continue;
            if(S[i]==atcoder[j]) dp[i+1][j+1] += dp[i][j];
        }
        rep(j,8) dp[i+1][j]%=MOD;
    }

    cout << dp[N][7] << endl;

}