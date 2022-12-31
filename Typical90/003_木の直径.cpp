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
// */
// 木の直径を求める
// 最短経路探索を2回行う
vector<ll> dist;
int N; // 頂点数

void getdist(const Graph &G,int start){
    // 幅優先探索(BFS)により最短経路を計算
    rep(i,N) dist[i] = INF;
    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        for(int to:G[pos]){
            if(dist[to]==INF){
                dist[to] = dist[pos]+1;
                Q.push(to);
            }
        }
    }
}

int main(){
    cin >> N;
    Graph G(N);
    // Step #1. 入力
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // Step #2. 頂点 0 からの最短距離を求める
	// maxid1: 頂点 0 から最も離れている（最短距離が長い）頂点
    dist.assign(N,-1);
    getdist(G,0);
    ll maxn1 = -1,maxid1 = -1;
    rep(i,N){
        if(chmax(maxn1,dist[i])) maxid1 = i;
    }

    // Step #3. 頂点 maxid1 からの最短距離を求める
	// maxn2: 木の直径（最短距離の最大値）
    getdist(G,maxid1);
    ll maxn2 = -1;
    rep(i,N) chmax(maxn2,dist[i]);
    
    // 出力
    int ans = maxn2 + 1;
    cout << ans << endl;
}
