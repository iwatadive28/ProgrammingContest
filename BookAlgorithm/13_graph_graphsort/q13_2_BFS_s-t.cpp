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
vector<int> dist; // BFS に用いる距離配列
vector<int> BFS(const Graph &G, int s){
    queue<int> que;

    // 初期条件（頂点0を初期頂点とする）
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
    int N,M,s,t;
    cin >> N >> M >> s >> t;
    s--;t--;
    
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b); // 無向グラフ
        G[b].push_back(a);
    }

    // 頂点sをスタートとした探索
    dist.assign(N,-1);
    BFS(G,s); // 頂点sを始点としたDFS
    cout << (dist[t]!=-1?"Yes":"No") << endl;
}
