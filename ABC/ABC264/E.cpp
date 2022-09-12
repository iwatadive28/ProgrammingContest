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
    int N,M,E,Q;
    cin >> N >> M >> E;
    vector<int> U(E),V(E);
    Graph G(N+M);
    rep(i,E){
        cin >> U[i] >> V[i];
        U[i]--;V[i]--;
    }

    vector<bool> ln(E,true); // 最終的に繋がっている線
    cin >> Q;
    vector<int> X(Q);
    rep(i,Q) {
        cin >> X[i];
        X[i]--;
        ln[X[i]] = false;
    }

    UnionFind uf(N+M);
    
    ll cur = 0; // 現在電気の通っている都市は0

    // 各辺を破壊ではなく、追加していく
    // 最終状態
    vector<int> w(N+M,0);
    for(int i=N;i<N+M;i++){w[i]=1;}

    rep(i,E){
        if(!ln[i]) continue;
        if (uf.issame(U[i],V[i])) continue;
        int fu = w[uf.root(U[i])];
        int fv = w[uf.root(V[i])];
        if(fu==0 && fv==1) cur+=uf.size(U[i]);
        if(fu==1 && fv==0) cur+=uf.size(V[i]);

        uf.unite(U[i],V[i]);
        w[uf.root(U[i])] = max(fu,fv);
    }
    
    vector<ll> ans;
    for(int j=Q-1;j>=0;--j){
        int i=X[j];
        ans.push_back(cur);

        if(uf.issame(U[i],V[i])) continue;
        int fu = w[uf.root(U[i])];
        int fv = w[uf.root(V[i])];
        if(fu==0 && fv==1) cur+=uf.size(U[i]);
        if(fu==1 && fv==0) cur+=uf.size(V[i]);

        uf.unite(U[i],V[i]);
        w[uf.root(U[i])] = max(fu,fv);
    }
        
    reverse(ans.begin(),ans.end());
    for(auto n:ans) cout << n << endl; 
}
