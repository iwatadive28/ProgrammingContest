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
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    // 初期化
    pair<int,int> pr[N];
    rep(i,N) pr[i] = make_pair(0,i);
    
    // 点を加算
    rep(i,N) --pr[a[i]].first;    
    
    // SORT
    sort(pr,pr+N);

    // Output
    rep(i,N) cout << pr[i].second << " " << -pr[i].first << endl;
    
    return 0;
}