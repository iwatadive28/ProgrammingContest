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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
/*
*/

// トポロジカルソート
ll ans;
ll limit = 1000000;
vector<bool> seen;
void dfs(const Graph &G,int v){
    if (ans == limit) return;
    ans++;
    // cout << ans << endl;
    seen[v] = true;
    for(auto next_v:G[v]){
        if(seen[next_v]) continue;
        dfs(G,next_v);
    }
    seen[v] = false;
}


int main(){
    int N,M; // 頂点数、辺数
    cin >> N >> M;

    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    seen.assign(N,false);    // 初期状態ではすべて未訪問
    ans=0;
    dfs(G,0);
    
    cout << ans << endl;
    
}