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
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S[i];

    vector<vector<ll>>  dp(N+1,vector<ll>(2,0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    rep(i,N){
        rep(j,2){
            if(dp[i][j]==0) continue;
            rep(x,2){
                if(S[i]=="AND") dp[i+1][j&&x] += dp[i][j];
                else            dp[i+1][j||x] += dp[i][j];
            }
        }
    }
    /*
    rep(i,N+1){
        rep(j,2){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }// */

    cout << dp[N][1] << endl;
}