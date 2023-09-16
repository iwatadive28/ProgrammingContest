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

    vector<ll> X(N),Y(N),Z(N);
    rep(i,N) cin >> X[i] >> Y[i] >> Z[i];

    ll z_sum = 0;
    rep(i,N) z_sum += Z[i];
    vector<ll> dp(z_sum+1,INF);
    dp[0] = 0;

    rep(i,N){
        ll x=X[i];
        ll y=Y[i];
        ll z=Z[i];
        ll w = max((ll)0,(x+y)/2+1-x); //寝返る人数
        // for(ll j=z;j<=z_sum;j++){
        for(ll j=z_sum;j>=z;j--){
            chmin(dp[j],dp[j-z]+w);
        }
    }
    
    ll ans = INF;
    for(int j = z_sum/2+1; j<=z_sum; j++){
        chmin(ans,dp[j]);
    }
    cout << ans << endl;
}