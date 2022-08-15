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
bool ans = false;
vector<bool> seen;

void dfs(int pos,int t){
    seen[pos] = true;
    if (pos==t){
        ans = true;
        return;
    }
    
    for(int n:G[pos]){
        if (seen[n]) continue;
        dfs(n,t);
        if(ans) break;
    }
    return;
}

int main(){
    int N;
    int sx,sy,tx,ty;
    cin >> N >> sx >> sy >> tx >> ty;
    
    ll s,t;
    vector<int> x(N),y(N),r(N);
    rep(i,N){
        cin >> x[i] >> y[i] >> r[i];
        double d  = sqrt(pow(sx-x[i],2) + pow(sy-y[i],2));
        double rr = sqrt(pow(r[i],2));
        if (abs(d-rr)<=1e-6) {
            s = i;
        }
        d = sqrt(pow(tx-x[i],2)+ pow(ty-y[i],2));
        if (abs(d-rr)<=1e-6){
            t = i;
        }
    }
    // Graph
    G.resize(N);
    rep(i,N-1){
        for(ll j=i+1;j<N;++j){
            double d   = sqrt(pow(x[i]-x[j],2) + pow(y[i]-y[j],2));
            double rr1 = sqrt(pow(r[i]-r[j],2));
            double rr2 = sqrt(pow(r[i]+r[j],2));
            
            if (rr1-d <= 1e-6 && d-rr2 <= 1e-6){ // 外接+内接
                G[i].push_back(j);
                G[j].push_back(i);// 無向グラフの場合、逆の辺も張る
            }
        }
    }

    seen.resize(N);
    rep(i,N) seen[i]=false;    
    dfs(s,t); 
    cout << (ans?"Yes":"No") << endl;    
}
