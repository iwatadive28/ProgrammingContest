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
Graph G;
bool ans = false;
vector<bool> vis;

ull pow2(ll x){
    return x*x;
}

void dfs(int pos,int t){
    vis[pos] = true;
    if (pos==t){
        ans = true;
        return;
    }
    
    for(int n:G[pos]){
        if (vis[n]) continue;
        dfs(n,t);
        if(ans) break;
    }
    return;
}

int main(){
    int N;
    int sx,sy,tx,ty;
    cin >> N >> sx >> sy >> tx >> ty;
    
    ll s,t;
    vector<int> x(N),y(N),r(N);
    rep(i,N){
        cin >> x[i] >> y[i] >> r[i];
        ll d = pow2(sx-x[i]) + pow2(sy-y[i]);
        ll rr = pow2(r[i]);
        if (d == rr) {
            s = i;
        }
        d = pow2(tx-x[i])+ pow2(ty-y[i]);
        if (d == rr){
            t = i;
        }
    }
    // Graph
    G.resize(N);
    rep(i,N-1){
        for(ll j=i+1;j<N;++j){
            ll d   = pow2(x[i]-x[j]) + pow2(y[i]-y[j]);
            ll rr1 = pow2(r[i]-r[j]);
            ll rr2 = pow2(r[i]+r[j]);
            
            if (rr1 <= d && d <= rr2){ // 外接+内接
                G[i].push_back(j);
                G[j].push_back(i);// 無向グラフの場合、逆の辺も張る
            }
        }
    }

    vis.resize(N);
    rep(i,N) vis[i]=false;    
    dfs(s,t); 
    cout << (ans?"Yes":"No") << endl;    
}
