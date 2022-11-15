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
    
    // BFS
    queue<int> que;
    que.push(1);
    set<int> S;
    S.insert(1);
    
    // BFS開始（queが空になるまで探索を行う）
    while(!que.empty()){
        int v = que.front(); // queから先頭頂点を取り出す
        que.pop();

        // vから辿れる頂点をすべて調べる
        for(auto x:G[v]){
            if(S.count(x)) continue; // 発見済みの頂点は探索しない
            S.insert(x);
            que.push(x); // queに挿入
        }
    }
    
    cout << *S.rbegin() << endl;
}
