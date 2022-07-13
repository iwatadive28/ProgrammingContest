#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//
ll func_max(ll a,ll b){
    ll res;
    if(a>b) return a;
    else    return b;
}

int main(){
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    pair<ll,ll> mod_a[n];
    rep(i,n){
        ll am = a[i]%x;
        // if (am==0) am = x;
        mod_a[i] = make_pair(am,a[i]);
    }
    
    sort(mod_a,mod_a+n);
    // 無駄にならない範囲でクーポンを使っていく
    rep(i,n){
        if(k==0) break;
        ll tk = floor((double)mod_a[i].second / (double)x );
        tk = min(k,tk);
        k -= tk;
        mod_a[i].second -= tk*x;
    }

    // クーポンが無駄にならない順=modが大きい順にクーポンを使っていく
    rep(j,n){
        if (k==0) break; 
        ll i = n-j-1;
        ll tk = ceil((double)mod_a[i].second / (double)x);
        k -= min(k,tk); // クーポン消費

        mod_a[i].second = func_max(mod_a[i].second-x*tk,0); // 割引後の金額            
    }
    
    
    ll ans = 0;
    rep(i,n){
        ans += mod_a[i].second;
        // cout << mod_a[i].second << endl;
    }
    cout << ans << endl;
}