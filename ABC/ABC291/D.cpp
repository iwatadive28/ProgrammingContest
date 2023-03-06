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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353;
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll N;
    cin >> N;
    vector<vector<ll>> data(N,vector<ll>(2,0));;
    rep(i,N) cin >> data[i][0] >> data[i][1];

    vector<vector<ll>>  dp(N,vector<ll>(2,0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for(ll i=1;i<N;++i){
        rep(pre,2){      // 0:表,1:裏
            rep(nxt,2){  // 0:表,1:裏
                if(data[i-1][pre]!=data[i][nxt]){
                    dp[i][nxt] += dp[i-1][pre];
                }
            }
        }
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }

    // rep(i,N) cout << dp[i][0] << "," << dp[i][1] << endl;

    ll ans = (dp[N-1][0] + dp[N-1][1])%MOD;
    cout << ans << endl;
}