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
// 最大公約数
// ユークリッドの互除法
// O(log(m+n))
ll GCD(ll m,ll n){
    // Base Case
    if (n==0) return m;
    ll res;
    res = GCD(n,m % n);
    return res;
}

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    // 最大公約数 gcd
    ll tmp = GCD(GCD(a,b),c);
    ll ans = (a/tmp-1)+(b/tmp-1)+(c/tmp-1);
    cout << ans << endl;
}