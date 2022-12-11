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

int main(){
    ll N,K,D;
    cin >> N >> K >> D;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    
    
    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(K+1,vector<ll>(D,-1)));
    dp[0][0][0] = 0;

    // 配るDP
    rep(i,N){
        rep(j,K+1){
            rep(k,D){
                if(dp[i][j][k]==-1) continue;
                // a_iを選ばない場合
                chmax(dp[i+1][j][k],dp[i][j][k]);

                // a_iを選ぶ場合
                if(j!=K){
                    chmax(dp[i+1][j+1][(k+a[i])%D],dp[i][j][k]+a[i]);
                }
                //*/
            }
        }
    }
    /*
    rep(i,N+1){
        rep(j,K+1){
            cout << dp[i][j][0] << " ";
        }
        cout << endl;
    }
    //*/
    cout << dp[N][K][0] << endl;
}