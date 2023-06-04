#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
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
    ll N,M;
    cin >> N >> M;
    UnionFind uf(N);
    rep(i,M){
       int a,b;
       cin >> a >> b;
       a--;b--;
       uf.unite(a,b);
    }
    
    ll K;
    cin >> K;
    set<pair<int,int>> stxy;
    rep(i,K){
        int x,y;
        cin >> x >> y;
        x--;y--;
        if(uf.issame(x,y)) continue;
        stxy.insert({uf.root(x),uf.root(y)});
        stxy.insert({uf.root(y),uf.root(x)});
    }

    ll Q;
    cin >> Q;
    
    vector<bool> ans(Q,true);
    rep(i,Q){
        int p,q;
        cin >> p >> q;
        p--;q--;
        if(stxy.count({uf.root(p),uf.root(q)})) ans[i] = false;
    }    
    for(auto a:ans) cout << (a?"Yes":"No") << endl;
}