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
// グラフGにおいて、頂点sを始点とした探索を行う
void search(const Graph &G, int s){
    int N = (int)G.size(); // グラフの頂点数    
    // グラフ探索のためのデータ構造
    vector<bool> seen(N,false); // すべて未発見の状態
    queue<int>   todo;          // 空の状態(深さ優先探索では stack<int>)

    // 初期条件
    seen[s] = true; // sは探索済みとする
    todo.push(s);   // todoはsのみ含む状態とする

    while(!todo.empty()){ // todoが空になるまで探索を行う
        int v = todo.front(); // todoから頂点を取り出す
        todo.pop();

        for(int x:G[v]){  // vから辿れる頂点をすべて調べる
            if(seen[x]) continue; // すでに発見済みの頂点は探索しない
            seen[x] = true;       // 新たな頂点xを探索済み
            todo.push(x);         // todoに挿入
        }
    }
}

int main(){
    int N,M; // 頂点数:N,辺数:M
    cin >> N >> M;
    // グラフの入力受取（ここでは有向グラフ）
    Graph G(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        // G[b].push_back(a); // 無向グラフの場合、逆も挿入
    }
    // 頂点0からスタートした探索
    search(G,0); 
}