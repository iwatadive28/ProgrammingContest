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
int rec(int v){
    if(dp[v]!=-1) return dp[v]; // 既に更新済み

    int res = 0;
    for(auto nv:G[v]){
        chmax(res,rec(nv)+1); // 距離を+1して再帰的に解いていく
    }
    return dp[v] = res; // メモしながらリターン
}

int main(){
    // 頂点数, 変数
    int N,M;
    cin >> N >> M;
    G.assign(N,vector<int>());
    rep(i,M){
        int a,b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
    }

    // 初期化
    dp.assign(N,-1);

    // 全ノードを一通り更新しながら答えを求める
    int res = 0;
    rep(v,N) chmax(res,rec(v));
    cout << res << endl;

}
