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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i,H) cin >> a[i];

    vector<vector<ll>> dp(H,vector<ll>(W,0));
    dp[0][0] = 1;

    rep(i,H){
        rep(j,W){
            if(i+1<H){
                if(a[i+1][j]=='.'){
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= MOD;
                }
            }
            if(j+1<W){
                if(a[i][j+1]=='.'){
                    dp[i][j+1] += dp[i][j];
                    dp[i][j+1] %= MOD;
                }
            }                        
        }
    }
    cout << dp[H-1][W-1] << endl;
}
