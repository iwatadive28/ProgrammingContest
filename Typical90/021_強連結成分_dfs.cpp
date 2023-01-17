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
vector<bool> seen;
vector<int> I;

void dfs(const Graph &G,int v){
    seen[v] = true;
    for(auto nv:G[v]){
        if(seen[nv]) continue;
        dfs(G,nv);
    }
    I.push_back(v);
}

ll cnts; // 有向サイクル内の頂点数をカウント
void dfs2(const Graph &G,int v){
    seen[v] = true;
    cnts++;
    for (auto nv : G[v]){
        if(seen[nv]) continue;
        dfs2(G,nv);
    }
}

// 強連結成分
int main(){
    int N,M;
    cin >> N >> M;
    
    Graph G(N);
    Graph H(N); // 逆向きのグラフ
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        H[b].push_back(a);
    }

    // dfs
    // 帰りがけにIに追加していく
    seen.assign(N,false);
    rep(i,N){
        if(seen[i]) continue;
        dfs(G,i);
    }

    // 
    ll ans = 0;
    reverse(I.begin(),I.end());
    seen.assign(N,false);
    for(auto i:I){
        if(seen[i]) continue;
        cnts = 0;
        dfs2(H,i);
        // 有向サイクル中の頂点数 cnts の場合、2点を行き来するパターンは
        // cntsC2 = cnts*(cnts-1)/2; 
        ans += cnts * (cnts-1) / 2;
    }

    cout << ans << endl;

}