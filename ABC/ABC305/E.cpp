#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
// using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
// template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
// template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
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
    int N,M,K;
    cin >> N >> M >> K;

    // グラフ
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(Edge(b,-1));
        G[b].push_back(Edge(a,-1));
    }
    vector<int> p(K),h(K);
    rep(i,K){
        cin >> p[i] >> h[i];
        p[i]--;
    }

    // ダイクストラ法
    // vector<bool> used(N,false);
    vector<ll> dist(N,-1);
    
    // (d[v],v) のペアを要素としたヒープを作る
    priority_queue<pair<ll,int>,
                vector<pair<ll,int>>> que;
    rep(i,K){
        que.push({h[i],p[i]});
        dist[p[i]] = h[i];
    }
    
    // ダイクストラ法の反復を開始
    while(!que.empty()){
        // x: v に対するキー値
        // v: 使用済みでない頂点のうち、dist[v]が最大の頂点
        int x = que.top().first;
        int v = que.top().second;
        que.pop();
        
        // d > dist[v]は(d,v)がゴミであることを意味する
        if(dist[v]!=x) continue;
        // 頂点v を始点とした各辺を緩和
        for(auto e:G[v]){
            if(chmax(dist[e.to],dist[v]+e.w)){
                // 更新があるならヒープを新たに挿入
                que.push({dist[e.to],e.to});
            }
        }
    }

    set<int> ans;
    rep(i,N){
        // cout << dist[i] << endl;
        if(dist[i]>=0) ans.insert(i+1);
    }

    cout << ans.size() << endl;
    for(auto a:ans) cout << a << " ";
    cout << endl;

}