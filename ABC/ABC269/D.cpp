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

// 6方向を表す
int dx6[6]={-1,-1,0,0,1,1};
int dy6[6]={-1,0,-1,1,0,1};

int main(){
    int n;
    cin >> n;

    // Union-Findを要素数nで初期化
    UnionFind uf(n);
    vector<vector<int>> mem(2010,vector<int>(2010,-1));
    vector<int> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
        x[i]+=1001;
        y[i]+=1001;
        mem[x[i]][y[i]] = i;
    }

    // 各辺に対する処理
    rep(i,n){
        rep(k,6){
            // 6方向を確認して塗りつぶしたマスがあればマージする
            int nx = x[i]+dx6[k];
            int ny = y[i]+dy6[k];
            if(mem[nx][ny]>=0){
                uf.unite(i,mem[nx][ny]); // i 番目に塗りつぶしたマスとマージ
            }            
        }
    }

    // 集計
    int res = 0;
    rep(i,n){
        if(uf.root(i)==i) ++res;
    }    
    cout << res << endl;
    
}