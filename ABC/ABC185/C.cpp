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
const ull INF = 1LL << 60;  //無限大
const ull MOD = 1000000007; //10^9 + 7
/*
*/
//
ll comb(ll n,ll m){
    ll res = 1;
    rep(i,m){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

int main(){
    int L;
    cin >> L;
    
    ll ans = comb(L-1,11);
    cout << ans << endl;
}
