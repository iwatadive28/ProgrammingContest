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
int GCD(ll m,ll n){
    // Base Case
    if (n==0) return m;
    ll res;
    res = GCD(n,m % n);
    return res;
}

int main(){
    ll N,X;
    cin >> N >> X;
    vector<ll> x(N+1);
    rep(i,N) cin >> x[i];
    x[N] = X;
    
    sort(x.begin(),x.end());
    ll ans = x[1] - x[0];
    for(ll i=1;i<N;++i){
        ll d = x[i+1]-x[i];
        ans = GCD(ans,d);
    }
    cout << ans << endl;    
}
