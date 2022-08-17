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
    ll N,W;
    cin >> N >> W;
    vector<ll> w(N),v(N);
    ll sum = 0;
    rep(i,N){
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    
    // 初期化
    vector<vector<ll>> dp(N+1,vector<ll>(sum+1,INF));
    dp[0][0] = 0;
    
    // 配るDP
    rep(i,N){
        rep(j,sum){
            if(dp[i][j]==-1) continue;
            // i番目の品物を選ぶ場合
            if(j+v[i]<=sum){
                chmin(dp[i+1][j+v[i]],dp[i][j]+w[i]);            
            }
            // 選ばない場合
            chmin(dp[i+1][j],dp[i][j]);
        }        
    }

    for(ll j=sum;j>=0;--j){
        if(dp[N][j]<=W) {
            cout << j << endl;
            break;
        }
    } 
}
