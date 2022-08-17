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
    ll N,K,L;
    cin >> N >> K >> L;
    UnionFind road(N),train(N);
    rep(i,K){
        int p,q;
        cin >> p >> q;
        --p;--q;
        road.unite(p,q);
    }
    rep(i,L){
        int r,s;
        cin >> r >> s;
        --r;--s;
        train.unite(r,s);
    }

    // 各都市を分類する
    // (道路に関する Union-Find 上での根の番号, 鉄道に関する Union-Find 上での根の番号)
    // というペア値によって分類する
    map<pair<ll,ll>,ll> nums;
    rep(i,N){
        ll root_road  = road.root(i);
        ll root_train = train.root(i);
        nums[{root_road,root_train}]++;
    }

    // 答え
    rep(i,N){
        ll root_road  = road.root(i);
        ll root_train = train.root(i);
        cout << nums[{root_road,root_train}] << " ";
    }
    cout << endl;
}
