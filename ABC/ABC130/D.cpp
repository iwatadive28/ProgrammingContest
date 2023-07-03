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
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N,0);
    rep(i,N) cin >> a[i];

    // 累積和
    vector<ll> sum(N+1);
    sum[0]=0;
    rep(i,N) sum[i+1] = sum[i]+a[i];
    
    ll ans = 0;
    ll r = 0;
    // 尺取り法
    for(ll l=0;l<N;l++){
        chmax(r,l);
        while(r<N){
            ll tmp = sum[r+1]-sum[l];
            if(tmp>=K) break;
            r++;
        }
        ans += N-r;
    }
    cout << ans << endl;
}