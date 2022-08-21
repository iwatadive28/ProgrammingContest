#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
// using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
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

// 緩和を実施する関数
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}

int main(){
    // 頂点数, 変数, 始点
    int N,M,s;
    cin >> N >> M >> s;

    // グラフ
    Graph G(N);
    rep(i,M){
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }

    // ダイクストラ法
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
        // v: 使用済みでない頂点のうち、dist[v]が最小の頂点
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

    // 結果を出力
    rep(v,N){
        if(dist[v] < INF) cout << dist[v] << endl;
        else              cout << "INF"   << endl;
    }

}
