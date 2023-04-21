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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

// 入力：グラフGと、探索の始点s
// 出力：sから各頂点への最短路長を表す配列
ll ans = 0;
vector<ll> dist; // BFS に用いる距離配列
vector<ll> cnt;  // 

void BFS(const Graph &G, int s){
    queue<int> que;

    // 初期条件（頂点0を初期頂点とする）
    dist[s] = 0;
    cnt[s] = 1;
    que.push(s); // 0を未訪問, queに加える

    // BFS開始（queが空になるまで探索を行う）
    while(!que.empty()){
        int v = que.front(); // queから先頭頂点を取り出す
        que.pop();

        // vから辿れる頂点をすべて調べる
        for(auto x:G[v]){
            if(dist[x] == -1){
                dist[x] = dist[v]+1; // 距離情報を更新
                que.push(x);         // queに挿入
                cnt[x] = cnt[v];
            }else if(dist[x]==dist[v]+1){
                cnt[x] += cnt[v];
                cnt[x]%=MOD;
            }            
        }
    }
    return;
}

int main(){
    ll N,M;
    cin >> N >> M;
    Graph G(N);
    rep(i,M){
       int a,b;
       cin >> a >> b;
       a--;b--;
       G[a].push_back(b);
       G[b].push_back(a);
    }

    // 頂点sをスタートとした探索
    ans = 0;
    dist.assign(N,-1);
    cnt.assign(N,0);
    BFS(G,0); // 頂点sを始点としたBFS
    cout << cnt[N-1]<< endl;
}