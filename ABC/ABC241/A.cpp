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

int main(){
    
    vector<ll> a(10);
    int k=0;
    rep(i,10) cin >> a[i];
    rep(i,10){
        if (a[i]==0) k = i; break;
    }

    int ans;
    rep(i,3){        
        ans = a[k];
        k   = a[k];
    }
    cout << ans << endl;   
    
    
}