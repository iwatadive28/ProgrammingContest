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
// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true; // vを訪問済みとする
    for(auto next_v:G[v]){
        if(seen[next_v]) continue; // next_vが訪問済みならスルー
        dfs(G,next_v); // 再帰的に探索
    }
}

int main(){
    int N,M; // 頂点数:N,辺数:M
    cin >> N >> M;
    // グラフの入力受取（ここでは有向グラフ）
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        // G[b].push_back(a); // 無向グラフの場合、逆も挿入
    }
    // 頂点0からスタートした探索
    seen.assign(N,false); // 初期状態では全頂点が未訪問
    dfs(G,0); 
}