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
vector<int> pm = {1,-1};
vector<int> dist;
int N,M; // 頂点数,辺数

int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<int,int>> xy;
    for(int x=0;x<=N;x++){
        for(int y=0;y<=N;y++){
            if(x*x + y*y == M) xy.push_back({x,y});
        }
    }
    /*
    for(auto dxy :xy){
        int dx = dxy.first;
        int dy = dxy.second;
        cout << dx << " " << dy << endl;
    }
    // */

    // 幅優先探索(BFS)により最短経路を計算
    vector<vector<int>> dist(N,vector<int>(N,-1));    
    queue<pair<int,int>> Q;
    Q.push({0,0});
    dist[0][0] = 0;
    while(!Q.empty()){
        pair<int,int> pos = Q.front();
        Q.pop();
        int x = pos.first;
        int y = pos.second;
        for(auto dxy:xy){
            for(auto k:pm) for(auto l:pm){
                int dx = dxy.first  * k;
                int dy = dxy.second * l;
                if(x+dx>=N || y+dy>=N || x+dx<0 || y+dy<0) continue;
                if(dist[x+dx][y+dy]==-1){
                    dist[x+dx][y+dy] = dist[x][y]+1;
                    Q.push({x+dx,y+dy});
                }
            }
        }
    }  
    
    rep(i,N){
        rep(j,N){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
}