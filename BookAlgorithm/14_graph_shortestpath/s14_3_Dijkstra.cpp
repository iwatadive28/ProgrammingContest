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
    rep(i,N){ // O(N^2)
        // 「使用済み」出ない頂点のうち、distが最小の頂点を探す
        ll  min_dist = INF; // 最短距離
        int min_v    = -1;  // 最短距離の頂点
        rep(v,N){ // O(N)
            if(!used[v] && dist[v] < min_dist){
                min_dist = dist[v];
                min_v = v;
            }
        }

        // もしそのような頂点が見つからなければ終了する
        if(min_v==-1) break;

        // min_v を始点とした各辺を緩和する
        for(auto e:G[min_v]){
            chmin(dist[e.to],dist[min_v]+e.w);
        }
        used[min_v] = true; // min_vを「使用済み」とする        
    }
}
