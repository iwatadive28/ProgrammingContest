#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
const ll INF = 1e9+10;
/*
*/
//
ll n,q;
vector<ll> a,x;
int main(){
    cin >> n >> q;
    a.resize(n);
    x.resize(q);
    rep(i,n) cin >> a[i];
    rep(i,q) cin >> x[i];
    
    int ans = 0;
    // 二分探索 O(qlog(n))
    sort(a.begin(),a.end());
    a.push_back(INF);
    rep(i,q){
        // x[i]以上の範囲で最小のインデックスを返す
        ll iter = lower_bound(a.begin(),a.end(),x[i]) - a.begin();
        cout << n-iter << endl;
    }
}