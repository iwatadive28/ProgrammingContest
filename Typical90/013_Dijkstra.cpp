#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/

// 辺を表す型, ここでは重みを表す方をlong long型とする
struct Edge{
    int to; // 隣接頂点番号
    ll  w;  // 重み
    Edge(int to,ll w) : to(to),w(w){}
};

// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

// ダイクストラ法
vector<ll> Dijkstra(const Graph &G, int s,int t){
    // Input: G,s,t
    // Output: dist
    int N = G.size();
    vector<bool> used(N,false);
    vector<ll>   dist(N,INF);
    dist[s] = 0;
    
    // (d[v],v) のペアを要素としたヒープを作る
    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> que;
    que.push(make_pair(dist[s],s));
    
    // ダイクストラ法の反復を開始
    while(!que.empty()){
        // v: 使用済みでない頂点のうち、time[v]が最小の頂点
        // d: v に対するキー値
        int v = que.top().second;
        ll  d = que.top().first;
        que.pop();

        // d > dist[v]は(d,v)がゴミであることを意味する
        if(d > dist[v]) continue;

        // 頂点v を始点とした各辺を緩和
        for(auto e:G[v]){
            if(chmin(dist[e.to],dist[v]+e.w)){
                // 更新があるならヒープを新たに挿入
                que.push({dist[e.to],e.to});
            }
        }
    }
    return dist;
}

int main(){
    int N,M;
    cin >> N >> M;
    Graph G(N);
    rep(i,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    // 非負の重み付きグラフの最短経路問題
    // ダイクストラ法
    // 両側から計算
    vector<ll> dists = Dijkstra(G,0,N-1);
    vector<ll> distt = Dijkstra(G,N-1,0);
    
    // 結果を出力
    rep(i,N){
        // cout << dists[i] << " , " << distt[i] << " : ";
        ll ans = dists[i]+distt[i];
        cout << ans << endl;
    }
}   