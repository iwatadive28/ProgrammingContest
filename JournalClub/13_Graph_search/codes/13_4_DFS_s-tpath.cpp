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
    int N,M,s,t; // 頂点数、辺数、スタート、ゴール
    cin >> N >> M >> s >> t;

    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    // 頂点sをスタートとした探索
    seen.assign(N,false);
    dfs(G,s);
    cout << (seen[t]?"Yes":"No") << endl;
}