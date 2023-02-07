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

// パスグラフ判定
// 
int main(){
    int N,M;
    cin >> N >> M;
    Graph G(N);
    rep(i,M){
        int u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // 辺と頂点数があわない
    if(M!=N-1){
        cout << "No" << endl;
        return 0;
    }

    // 1頂点から2本以上の辺が存在するとき
    rep(i,N){
        if(G[i].size() > 2){
            // cout << "G[" << i << "] Size is over 2" << endl;
            cout << "No" << endl;
            return 0;
        }
    }

    // BFS
    // 全頂点訪れるか
    vector<bool> reach(N);
    queue<int> que;
    reach[0] = true;
    que.push(0);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for (int v:G[u]){
            if(reach[v]) continue;
            reach[v] = true;
            que.push(v);            
        }
    }

    rep(i,N){
        if(!reach[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
