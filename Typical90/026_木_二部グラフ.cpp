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
// 二部グラフ判定(深さ優先探索)
// 二部グラフ出ない場合はfalseを返す
vector<int> color;
bool dfs(Graph &G,int v, int cur=0){
    color[v] = cur;
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
    int N;
    cin >> N;
    Graph G(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 木=二部グラフ
    // 二部グラフ判定
    // 全頂点を始点として探索
    color.assign(N,-1);
    rep(i,N){
        if(color[i]!=-1) continue;
        dfs(G,i);
    }

    // 多数派の頂点を判断
    int mjc = 0;
    int cnt = 0;
    rep(i,N) if(color[i]==0) cnt++;
    if(cnt<N/2) mjc = 1;

    // N/2まで出力
    cnt = 0;
    rep(i,N){
        if(color[i]==mjc){
            cout << i+1 << endl;
            cnt++;
        }
        if(cnt>=N/2) break;
    }
}