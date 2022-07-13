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
using Graph = vector<vector<int>>;

int main(){
    // INPUT
    ll N,M;
    cin >> N >> M;
    Graph G(N);
    vector<pair<int,int>> cnt(N);
    rep(i,N){
        cnt[i] = make_pair(0,i);
    }
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        cnt[a].first--;
        cnt[b].first--;
    }
    sort(cnt.begin(),cnt.end());

    sort(G[cnt[0].second].begin(),G[cnt[0].second].end());
    for (auto to:G[cnt[0].second]){
        cout << to << " ";
    }
    cout << endl;
    return 0;
}