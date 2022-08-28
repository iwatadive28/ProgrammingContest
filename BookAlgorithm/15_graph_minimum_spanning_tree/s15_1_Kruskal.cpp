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
// Union-Find
struct UnionFind{
    vector<int> par,siz;
    // 初期化
    UnionFind(int n):par(n,-1),siz(n,1){ }
    
    // 根を求める
    int root(int x){
        if(par[x]==-1) return x; // xの場合はxを返す
        else return par[x] = root(par[x]); // 再帰的にxの親の根を返す
    }

    // xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(int x,int y){
        return root(x)==root(y);
    }

    // xを含むグループとyを含むグループとを併合する
    bool unite(int x,int y){
        // x,yをそれぞれ根まで移動する
        x = root(x);
        y = root(y);

        // すでに同じグループの時は何もせず
        if(x == y) return false;

        // union by size (y側のサイズが小さくなるようにする)
        if(siz[x]<siz[y]) swap(x,y);

        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x){
        return siz[root(x)];
    }
};

// 辺e = (n,v) を{w(e), {u,v}}と表す
using Edge = pair<int, pair<int,int>>;

int main(){
    int N,M; // 頂点数と辺数
    cin >> N >> M;
    vector<Edge> edges(M); // 辺集合
    rep(i,M){
        int u,v,w; // w: 重み
        cin >> u >> v >> w;
        edges[i] = {w,{u,v}};
    }

    // 各辺を重みの小さい順にソートする
    // pair はデフォルトで第一要素→第二要素の辞書順ソート
    sort(edges.begin(),edges.end());

    // クラスカル法
    ll res = 0; // 重みの総和
    UnionFind uf(N);
    rep(i,M){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // 辺(u,v)でサイクルが形成される時には追加しない
        if (uf.issame(u,v)) continue;
        
        // 辺(u,v)を追加する
        uf.unite(u,v);
        res += w;
    }
    
    cout << res << endl;
}
