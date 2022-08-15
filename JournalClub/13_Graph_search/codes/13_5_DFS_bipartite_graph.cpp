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
// 二部グラフ判定(深さ優先探索)
vector<int> color;
bool dfs(Graph &G,int v, int cur = 0){
    color[v] = cur;
    for(auto next_v:G[v]){
        // 隣接頂点がすでに色確定していた場合
        if(color[next_v] != -1) { 
            if(color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }
        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if(!dfs(G,next_v,1-cur)) return false;
    }
    return true;
}
int main(){
    int N,M; // 頂点数、辺数
    cin >> N >> M;
    
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a); // 無向グラフ 
    }
    
    // 前頂点を始点として探索する
    color.assign(N,-1);
    bool is_bipartite = true;
    rep(v,N){
        if(color[v] != -1) continue; // vが探索済みならスルー
        if(!dfs(G,v)) is_bipartite = false;
    }
    cout << (is_bipartite?"Yes":"No") << endl;
}