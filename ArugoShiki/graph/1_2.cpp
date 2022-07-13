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
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    rep(i,N){
        sort(G[i].begin(),G[i].end());
        rep(j,G[i].size()){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}