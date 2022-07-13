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

ll func(ll x){
    return pow(x,2) + 2*x + 3;
}

int main(){
    ll t;
    cin >> t;

    ll ans = func(func(func(t)+t)+func(func(t)));    
    cout << ans << endl;
}