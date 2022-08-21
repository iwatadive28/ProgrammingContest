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

    // ベルマン・フォード法
    bool exist_negative_cycle = false; // 負閉路を持つかどうか
    vector<ll> dist(N,INF);
    dist[s] = 0;
    rep(i,N){
        bool update = false; // 更新が発生したかどうかを表すフラグ
        rep(v,N){
            // dist[v] == INF のときは頂点v からの緩和を行わない
            if(dist[v]==INF) continue;

            for(auto e:G[v]){
                // 緩和処理を行い、更新されたらupdate をtrue にする
                update = chmin(dist[e.to],dist[v]+e.w);
            }
        }
        // 更新が行われなかったら、すでに最短経路が求められている
        if(!update) break;

        // N回目の反復で更新が行われたならば、負閉路を持つ
        if(i==N-1 && update) exist_negative_cycle = true;
    }

    // 結果出力
    if(exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else{
        rep(v,N){
            if(dist[v]<INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }
}
