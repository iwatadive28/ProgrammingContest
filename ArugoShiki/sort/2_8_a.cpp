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
    ll N,K;
    cin >> N >> K;

    vector<pair<ll,ll>> M(N);
    rep(i,N) cin >> M[i].first >> M[i].second;

    // コスト少ない順→在庫多い順に並べる
    // SORT
    sort(M.begin(), M.end());

    // Kを超えるまで購入していく
    ll cost = 0;
    rep(i,N){
        ll num = min(M[i].second,K);
        K -= num;
        cost += num * M[i].first;
        if (K==0) break;
    }

    // Output
    cout << cost << endl;
    return 0;
}