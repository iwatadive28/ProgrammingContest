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
set<pair<int,int>> st;

void dfs(int s,int n){
    pair<int,int> sg = make_pair(s,n);
    if(st.count(sg))   return;
    else st.insert(sg); 
    
    for(auto next:G[n]) dfs(s,next);
    return;
}

int main(){
    int N,M;
    cin >> N >> M;

    G.resize(N+1);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
   
    rep(i,N) dfs(i+1,i+1);
    cout << st.size() << endl;
}
