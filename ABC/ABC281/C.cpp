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
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    // 累積和
    vector<ll> sum(n+1,0);
    rep(i,n){
        sum[i+1] = sum[i]+a[i];
    }
    
    ll x = t%sum[n];
    ll ans;
    ll res;
    rep(i,n){
        if(x/sum[i+1]==0){
            ans = i+1;
            res = x%sum[i+1]-sum[i];
            break;
        }
    }

    cout << ans << " " << res << endl;
}