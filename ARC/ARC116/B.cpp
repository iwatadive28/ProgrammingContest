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
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end(),greater<ll>()); // ,greater<ll>()
    
    // 累積和
    vector<ll> sum(N,0);
    sum[0] = A[0];
    rep(i,N-1) sum[i+1] = sum[i]+A[i+1];
    
    ll ans = 0;
    ll now = 0;
    rep(i,N){
        ans += now*A[i];
        ans += A[i]*A[i];
        ans %= MOD;
        now *= 2;
        now += A[i];
        now %= MOD;
    }
    cout << ans << endl;
}