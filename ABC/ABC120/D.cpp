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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M),B(M);
    rep(i,M){
        cin >> A[i] >> B[i];
        --A[i],--B[i];
    }

    UnionFind uf(N);
    vector<ll> ans(M);
    ll cur = N*(N-1)/2; // 困難さは最大 nC2
    // 各辺を破壊ではなく、追加していく
    rep(i,M){
        ans[i] = cur;

        // a,bを追加していく
        ll a = A[M-1-i];
        ll b = B[M-1-i]; 
        
        // すでに同じグループの時は何もせず
        if(uf.issame(a,b)) continue; 

        ll sa = uf.size(a);
        ll sb = uf.size(b);
        cur -= sa*sb;
        uf.unite(a,b);
    }

    reverse(ans.begin(),ans.end());
    for(auto n:ans) cout << n << endl;
}
