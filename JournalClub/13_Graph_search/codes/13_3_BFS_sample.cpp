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
// 入力：グラフGと、探索の始点s
// 出力：sから各頂点への最短路長を表す配列
vector<int> BFS(const Graph &G, int s){
    int N = (int)G.size();  // 頂点数
    vector<int> dist(N,-1); // -1=未訪問に初期化
    queue<int> que;

    // 初期条件（頂点0を書記長店とする）
    dist[s] = 0;
    que.push(s); // 0を未訪問, queに加える

    // BFS開始（queが空になるまで探索を行う）
    while(!que.empty()){
        int v = que.front(); // queから先頭頂点を取り出す
        que.pop();

        // vから辿れる頂点をすべて調べる
        for(auto x:G[v]){
            if(dist[x] != -1) continue; // 発見済みの頂点は探索しない
            dist[x] = dist[v]+1; // 距離情報を更新
            que.push(x);         // queに挿入
        }
    }
    return dist;
}

int main(){
    int N,M; // 頂点数:N, 変数:M
    cin >> N >> M;

    // グラフ入力受取(無向グラフを想定)
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点0を始点としたBFS
    vector<int> dist = BFS(G,0);
    
    // 結果出力(各頂点の頂点0からの距離を見る)
    rep(v,N) cout << v << ":" << dist[v] << endl;
}