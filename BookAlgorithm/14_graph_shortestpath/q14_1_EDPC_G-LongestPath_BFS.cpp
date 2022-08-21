#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;

// 緩和を実施する関数
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
using Graph = vector<vector<int>>;
/*
// 辺を表す型, ここでは重みを表す方をlong long型とする
struct Edge{
    int to; // 隣接頂点番号
    ll  w;  // 重み
    Edge(int to,ll w) : to(to),w(w){}
};
// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>; 
*/

Graph G; // グラフ
vector<int> dp;
vector<int> deg; // 各頂点の入次数

int main(){
    // 頂点数, 変数
    int N,M;
    cin >> N >> M;
    G.assign(N,vector<int>());
    deg.assign(N,0); //  入次数も管理する
    rep(i,M){
        int a,b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
        deg[b]++;
    }

    // source をキューに突っ込む
    queue<int> que;
    rep(v,N) if(deg[v]==0) que.push(v); // スタート

    // 初期化
    dp.assign(N,0);

    // BFS
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(auto nv:G[v]){
            deg[nv]--; // エッジ(v.nv) を破壊する
            if(deg[nv]==0){ // 次の頂点
                que.push(nv); // それによって入次数が0になったならキューに突っ込む
                chmax(dp[nv],dp[v]+1); // さらにソースからnv までの最長距離が確定する
            }
        }
    }

    // 全ノードを一通り更新しながら答えを求める
    int res = 0;
    rep(v,N) chmax(res,dp[v]);
    cout << res << endl;

}
