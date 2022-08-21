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
// 深さ優先探索
vector<bool> seen;
void dfs(Graph &G,int v){
    seen[v] = true;
    for(auto next_v:G[v]){
        if(seen[next_v]) continue;
        dfs(G,next_v);
    }
}

int main(){
    int N,M;
    cin >> N >> M;

    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b); // 無向グラフ
        G[b].push_back(a);
    }

    // 頂点sをスタートとした探索
    int res = 0;
    seen.assign(N,false);
    rep(s,N){
        if(seen[s]) continue;
        dfs(G,s); // 頂点sを始点としたDFS
        ++res;
    }
    cout << res << endl;
}
