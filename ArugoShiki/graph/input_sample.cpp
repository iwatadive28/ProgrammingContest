#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

using Graph = vector<vector<int>>;
/*
*/
//
int main(){
    // INPUT
    ll N,M;
    cin >> N >> M;
    Graph G(N);
    rep(i,N){
        int A,B;
        cin >> A >> B;
        // 頂点Aから頂点Bへの辺
        G[A].push_back(B);
        // 無向グラフの場合、逆の辺も張る
        G[B].push_back(A);
    }
        
    return 0;
}