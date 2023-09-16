#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
// using Graph = vector<vector<int>>;
// 辺を表す型, ここでは重みを表す方をlong long型とする
struct Edge{
    int to; // 隣接頂点番号
    ll  w;  // 重み
    Edge(int to,ll w) : to(to),w(w){}
};

// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int ans = -1;
// 深さ優先探索
vector<bool> seen;
void dfs(Graph &G,int v,int x){
    seen[v] = true;
    chmax(ans,x);
    
    for(auto e:G[v]){
        if(seen[e.to]) continue;
        dfs(G,e.to,x+e.w);
    }
    // 帰りがけにseenをリセット
    seen[v]=false;
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

    
    rep(i,N){
        // 頂点iをスタートとした探索
        seen.assign(N,false);
        dfs(G,i,0);
    }
    cout << ans << endl;
    
    
}