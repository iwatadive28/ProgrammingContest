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

// Union-Find
struct UnionFind{
    vector<ll> par,siz;
    // 初期化
    UnionFind(ll n):par(n,-1),siz(n,1){ }
    
    // 根を求める
    ll root(ll x){
        if(par[x]==-1) return x; // xの場合はxを返す
        else return par[x] = root(par[x]); // 再帰的にxの親の根を返す
    }

    // xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(ll x,ll y){
        return root(x)==root(y);
    }

    // xを含むグループとyを含むグループとを併合する
    bool unite(ll x,ll y){
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
    ll size(ll x){
        return siz[root(x)];
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    // 閉路探索
    UnionFind uf(N);
    int cnt = 0;
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(uf.root(a)==uf.root(b)){
            cnt++;
        }        
        uf.unite(a,b);
    }
    cout << cnt << endl;
}
