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
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
ll llabs(ll x){
    if (x<0) return -x;
    else return x;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n),B(m);
    rep(i,n) cin >> A[i];
    rep(i,m) cin >> B[i];
    
    // SORT
    sort(B.begin(),B.end());
    B.push_back(INF);

    ll ans = INF;
    for(ll a:A){
        // a以上の範囲で最小の値
        auto iter_l = lower_bound(B.begin(),B.end(),a);
        ll val_l = *iter_l;
        ans = min(ans,llabs(a-val_l));

        // a以下で最も大きい値
        auto iter_u = upper_bound(B.begin(),B.end(),a);
        if (iter_u != B.begin()){
            iter_u--;
            ll val_u = *iter_u;
            ans = min(ans,llabs(a-val_u));
        }
        // cout << "a,val_l,val_u = " << a << "," << val_l << "," << val_u << endl;
    }
    cout << ans << endl;
}