#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
// 
// トポロジカルソート
vector<bool> seen;
vector<int> order; // トポロジカルソート順
void rec(const Graph &G,int v){
    seen[v] = true;
    for(auto next_v:G[v]){
        if(seen[next_v]) continue;
        rec(G,next_v);
    }
    // v-out(帰りがけ順)を記録する
    order.push_back(v);
}

int main(){
    int N,M; // 頂点数、辺数
    cin >> N >> M;

    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(N,false); // 初期状態ではすべて未訪問
    order.clear();        // トポロジカルソート順
    rep(v,N){
        if(seen[v]) continue;
        rec(G,v);
    }
    reverse(order.begin(),order.end()); // 逆順に
    
    // 出力
    for(auto v: order) cout << v << "->";
    cout << endl;
}