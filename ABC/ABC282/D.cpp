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
// 二部グラフ判定(深さ優先探索)

ll c2(ll x){
    return x*(x-1)/2;
}

vector<int> color;
vector<int> csv(2);   // 2部グラフのそれぞれの数
bool dfs(Graph &G,int v, int cur = 0){
    color[v] = cur;
    csv[cur]++;
    for(auto next_v:G[v]){
        // 隣接頂点がすでに色確定していた場合
        if(color[next_v] != -1) { 
            if(color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }
        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if(!dfs(G,next_v,1-cur)) return false;
    }
    return true;
}

int main(){
    int n,m;
    cin >> n >> m;
    Graph G(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans = c2(n) - m; // 結ばれてない頂点の組み合わせ

    // 二部グラフ判定
    color.assign(n,-1);
    rep(v,n){
        if(color[v] != -1) continue; // vが探索済みならスルー
        csv.assign(2,0); 
        if(!dfs(G,v)){
            cout << 0 << endl;
            return 0;
        }
        ans -= c2(csv[0]); // 同じ連結成分の同じ色の2つの組み合わせを引く
        ans -= c2(csv[1]); //
    }
    cout << ans << endl;

}