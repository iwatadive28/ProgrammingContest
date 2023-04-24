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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/
vector<int> dist;
int N,M; // 頂点数,辺数
void BFS(const Graph &G,int s){
    // 幅優先探索(BFS)により最短経路を計算
    // d まで計算
    rep(i,N) dist[i] = INF;
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;
    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        for(int to:G[pos]){
            if(dist[to]==INF){
                dist[to] = dist[pos]+1;
                Q.push(to);
            }
        }
    }
}

int main(){
    cin >> N >> M;
    Graph G(N);
    rep(i,M){
       int a,b;
       cin >> a >> b;
       a--;b--;
       G[a].push_back(b);
       G[b].push_back(a);
    }

    // 任意のkからの各頂点間の距離を求める.
    vector<vector<int>> dist2(N,vector<int>(N));
    rep(k,N){
        dist.assign(N,INF);
        BFS(G,k);
        dist2[k] = dist;
        // for(auto d:dist) cout << d << " ";
        // cout << endl;
    }
    // /*
    int K;
    cin >> K;
    bool ans = true;
    vector<int> color(N,-1);
    vector<int> P(K),D(K);
    rep(k,K){
        cin >> P[k] >> D[k];
        P[k]--;
        // 距離d未満の点は白確定
        rep(j,N){
            if(dist2[P[k]][j]<D[k]){
                color[j]=0;
            }
        }
    }

    // 白確定以外の点
    int cnt = 0;
    rep(i,N){
        if(color[i]==-1){
            color[i]*=-1;
            cnt++;
        }
    }
    // 1個以上の黒い点があるか
    if(cnt==0) ans=false;
    
    // check:黒からの距離を求める
    vector<int> dist_k(N,INF);
    rep(i,N){
        if(color[i]==0) continue;
        rep(j,N) chmin(dist_k[j],dist2[i][j]);
    }
    // for(auto a:dist_k) cout << a << " ";
    // cout << endl;
    rep(k,K){
        if(dist_k[P[k]]!=D[k]) ans = false;
    }
    
    if(ans){
        cout << "Yes" << endl;
        for(auto a:color) cout << a;
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    //*/
}