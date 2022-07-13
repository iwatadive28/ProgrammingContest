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

int main(){
    // INPUT
    ll N ,K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];    
        
    // SORT
    sort(a.begin(),a.end());
    
    ll ans = 1LL<<60;
    rep(i,N-K+1){
        ll diff = a[i+K-1] - a[i]; 
        ans = min(diff,ans);
    }
    cout << ans << endl;
     
    return 0;
}