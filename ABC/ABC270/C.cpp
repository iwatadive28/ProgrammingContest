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
// 深さ優先探索
vector<int>  seen;
void dfs(Graph &G,int v,int prev){
    seen[v] = prev;
    for(auto next_v:G[v]){
        if(seen[next_v]!=-1) continue;
        dfs(G,next_v,v);
    }
    //if(seen[t]) path.push_back(v);
}

int main(){
    int N,X,T; // 頂点数、スタート、ゴール
    cin >> N >> X >> T;
    X--;T--;
    Graph G(N);
    
    rep(i,N-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // 頂点Xをスタートとした探索
    seen.assign(N,-1);
    dfs(G,X,-9);
    
    /*
    for(auto x:seen) cout << x << " ";
    cout << endl;
    */

    vector<int> ans;
    int cur = T;
    while(true){
        // cout << cur+1 << " ";
        ans.push_back(cur+1);
        if(seen[cur]==-9) break;
        cur = seen[cur];
    }

    reverse(ans.begin(),ans.end());
    for(auto a:ans) cout << a << " ";
    cout << endl;
}