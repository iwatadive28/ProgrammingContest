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

int main(){
    UnionFind uf(7); // {0},{1},{2},{3},{4},{5},{6}

    uf.unite(1,2); // {0},{1,2},{3},{4},{5},{6}
    uf.unite(2,3); // {0},{1,2,3},{4},{5},{6}
    uf.unite(5,6); // {0},{1,2,3},{4},{5,6}
    cout << uf.issame(1,3) << endl; // true
    cout << uf.issame(2,5) << endl; // false

    uf.unite(1,6); // {0},{1,2,3,5,6},{4}
    cout << uf.issame(2,5) << endl; // true
}
