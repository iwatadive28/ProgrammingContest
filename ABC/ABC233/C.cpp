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
ll N,X;
ll ans = 0;
vector<vector<ll>> a;

void dfs(ll pos,ll seki){
    //
    if (pos==N){
        if (seki==X) ans++;
        return;
    }
    
    for(ll c:a[pos]){
        if (seki*c>X) continue;
        dfs(pos+1,seki*c);
    }
}

int main(){
    cin >> N >> X;
    a.resize(N);
    rep(i,N){
        ll L;
        cin >> L;
        a[i].resize(L);
        rep(j,L) cin >> a[i][j];
    }
    dfs(0,1);
    cout << ans << endl;
}