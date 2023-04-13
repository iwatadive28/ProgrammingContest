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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/
// 二部グラフ
vector<int> color;
vector<int> csv(2);   // 2部グラフのそれぞれの数
bool dfs(Graph &G,int v, int cur = 0){
    color[v] = cur;
    csv[cur]++;
    for(auto next_v:G[v]){
        // 隣接頂点がすでに色確定していた場合
        if(color[next_v] != -1) { 
            if(color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }
        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if(!dfs(G,next_v,1-cur)) return false;
    }
    return true;
}

int main(){
    ll N,Q;
    cin >> N >> Q;
    Graph G(N);
    rep(i,N-1){
       int a,b;
       cin >> a >> b;
       a--;b--;
       G[a].push_back(b);
       G[b].push_back(a);
    }

    // 二部グラフ判定
    color.assign(N,-1);
    rep(v,N){
        if(color[v] != -1) continue; // vが探索済みならスルー
        csv.assign(2,0); 
        if(!dfs(G,v)){
            cout << 0 << endl;
            return 0;
        }
    }

    vector<string> ans(Q);
    rep(i,Q){
        int c,d;
        cin >> c >> d;
        c--;d--;
        if(color[c]==color[d]) ans[i]="Town";
        else ans[i] = "Road";
    }

    for(auto a: ans) cout << a << endl;
}