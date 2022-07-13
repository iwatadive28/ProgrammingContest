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
    ll N ,M;
    cin >> N >> M;
    vector<ll> a(N),x(M);
    
    rep(i,N) cin >> a[i];    
    rep(i,M) cin >> x[i];    
        
    // SORT
    sort(a.begin(),a.end());
    
    rep(i,M){
        cout << a[x[i]] << endl;
    } 
    return 0;
}