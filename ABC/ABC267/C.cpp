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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    // 累積和
    vector<ll> sum(N+1,0);
    rep(i,N) sum[i+1] = sum[i]+A[i];

    vector<ll> sumi(N-M+1);
    ll now = 0;
    rep(i,M) now += (A[i]*(i+1));
    sumi[0] = now;

    for(ll i=1;i<N-M+1;++i){
        sumi[i] = sumi[i-1] + M*A[M+i-1] - (sum[M+i-1] -sum[i-1]);
    }

    ll ans = -INF;
    rep(i,N-M+1) chmax(ans,sumi[i]);
    
    cout << ans << endl;
}
