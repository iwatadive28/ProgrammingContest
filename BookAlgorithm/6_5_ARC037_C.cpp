#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//
const int INF = 20000000;
ll N,K;

bool check(ll x,vector<ll> a,vector<ll> b){
    ll cnt=0;
    rep(i,N){
        cnt += upper_bound(b.begin(),b.end(),x/a[i]) - b.begin();
    }
    return (cnt>=K);
}

int main(){
    // INPUT
    
    cin >> N >> K;
    vector<ll> a(N),b(N);
    rep(i,N) cin >> a[i];    
    rep(i,N) cin >> b[i];    
    
    // SORT
    sort(b.begin(),b.end());
    
    // 二分探索
    ll left  = 0;
    ll right = 1LL<<60;
    while(right - left > 1){
        ll mid = (right+left)/2;
        if (check(mid,a,b)) right = mid;
        else left = mid;
    }
    cout << right << endl;

    return 0;
}