#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//

int main(){
    int n;
    cin >> n;
    vector<ll> s(n),t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    
    vector<ll> st = t;
    rep(i,n*2) st[(i+1)%n] = min(st[i%n]+s[i%n],st[(i+1)%n]);
    rep(i,n) cout << st[i] << endl;
}