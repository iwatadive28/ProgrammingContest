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
ll powmod(ll x,ll y){
    ll res = 1;
    rep(i,y){
        res = (res*x)%MOD;
    }
    return res;
}

int main(){
    int N;
    cin >> N;

    ll ans = powmod(10,N) - powmod(9,N) - powmod(9,N) + powmod(8,N);
    ans %= MOD;
    ans = (ans+MOD)%MOD;
    cout << ans << endl;
}
