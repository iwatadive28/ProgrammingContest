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

int main(){
    ll N1,N2,M;
    cin >> N1 >> N2 >> M;
    Graph G(N1+N2);
    rep(i,M){
       int a,b;
       cin >> a >> b;
       a--;b--;
       G[a].push_back(b);
       G[b].push_back(a);
    }
    
    // BFS
    vector<ll> dist(N1+N2,-1); // BFS に用いる距離配列
    queue<ll> que;
    // 初期条件（頂点0を初期頂点とする）
    dist[0] = 0;
    que.push(0); 
    dist[N1+N2-1] = 0;
    que.push(N1+N2-1); 
    
    // BFS開始（queが空になるまで探索を行う）
    while(!que.empty()){
        int v = que.front(); // queから先頭頂点を取り出す
        que.pop();

        // vから辿れる頂点をすべて調べる
        for(auto x:G[v]){
            if(dist[x] != -1) continue; // 訪れた頂点の場合はスキップ
            dist[x] = dist[v]+1; // 距離情報を更新
            que.push(x);         // queに挿入
        }
    }
    
    ll mx1 = -1;
    ll mx2 = -1;
    for(ll i=0 ;i<N1   ;i++) chmax(mx1,dist[i]);
    for(ll i=N1;i<N1+N2;i++) chmax(mx2,dist[i]);

    cout << mx1+mx2+1 << endl;
}