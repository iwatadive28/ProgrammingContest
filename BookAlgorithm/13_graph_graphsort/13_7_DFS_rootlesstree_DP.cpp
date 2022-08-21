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
// 木上の探索
vector<int> depth;
vector<int> subtree_size;
// v: 現在探索中の頂点, p：vの親(vが根の時は-1), d:頂点vの深さ(vが根の時は0)
void dfs(const Graph &G, int v, int p = -1, int d = 0){
    depth[v] = d; // 行きがけ順
    for(auto c:G[v]){
        if(c==p) continue; // 親方向へ探索するのを防ぐ
        dfs(G,c,v,d+1);    // d を1増やして子頂点の探索に進む
    }
    // 帰りがけ(dfsから抜ける)時に、部分木サイズを求める
    subtree_size[v] = 1; // 自分自身
    for (auto c:G[v]){
        if(c==p) continue;
        subtree_size[v] += subtree_size[c]; // 子のサイズを加算する
    }
}

int main (){
    // 入力
    int N; cin >> N; // 頂点数(木なので辺数はN-1で確定)
    Graph G(N);
    rep(i,N-1){
        int a,b; cin >> a >> b;
        G[a].push_back(b); // 無向グラフ
        G[b].push_back(a);
    }

    // 探索
    int root = 0; // 頂点0を根とする
    depth.assign(N,0);
    subtree_size.assign(N,0);
    dfs(G,root);
    // 出力
    rep(v,N){
        cout << v << ",: depth = " << depth[v]
             << ",subtree_size = " << subtree_size[v] << endl; 
    }
}