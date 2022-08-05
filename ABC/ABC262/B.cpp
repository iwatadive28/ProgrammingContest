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
int main(){
    int N,M;
    cin >> N >> M;
    Graph G(N+1);
    rep(i,M){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);// 無向グラフの場合、逆の辺も張る
    }
    
    int ans = 0;
    rep(i,N){
        int a=i+1;
        for(auto b:G[a]){
            for(auto c:G[b]){
                for(auto n:G[c]){
                    if(n==a) ans++;
                }
            }
        }
    }

    cout << ans/6 << endl;   
}
