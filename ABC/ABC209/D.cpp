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
Graph G;
int dist(int x,int y){
    G(x)
}

int main(){
    int N,Q;
    cin >> N >> Q;
    G.resize(N+1);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(a);
        G[b].push_back(b);// 無向グラフの場合、逆の辺も張る
    }
    for(auto v:G){
        sort(v.begin(),v.end());
    }
    
    rep(i,Q){
        int c,d;
        cin >> c >> d;
        cout << "" << endl;
   }
}