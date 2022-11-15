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
set<int> S;
void dfs(map<int,vector<int>> &G, int v){
    S.insert(v); // vを訪問済みとする
    for(auto x:G[v]){
        if(S.count(x)) continue; // xが訪問済みならスルー
        dfs(G,x); // 再帰的に探索
    }
    return;
}

int main(){
    int N;
    cin >> N;
    map<int,vector<int>> G;
    rep(i,N){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    // DFS
    dfs(G,1);
    cout << *S.rbegin() << endl;
    
}
