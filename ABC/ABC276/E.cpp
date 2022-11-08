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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353; //998244353
/*
*/
vector<pair<int,int>> nx(4,{0,0});
bool ans = false;
int H,W;
    
// 入力：グラフGと、探索の始点s
// 出力：sから各頂点への最短路長を表す配列
vector<vector<int>> seen; // BFS に用いる配列・訪問済み
void BFS(vector<string> &C, pair<int,int> s){
    queue<pair<int,int>> que;
    int x = s.first;
    int y = s.second;

    // 初期条件（頂点0を初期頂点とする）
    seen[x][y] = 0;
    // que.push(s); // 0を未訪問, queに加える
    // 初手は自分の周りに1~4を入れる
    rep(i,4){
        int nx_x = x + nx[i].first;
        int nx_y = y + nx[i].second;
        if(nx_x<0 || nx_y<0 || nx_x>=H || nx_y>=W) continue;
        if(C[nx_x][nx_y] == '#') continue;
        seen[nx_x][nx_y] = i+1;
        que.push({nx_x,nx_y}); // queに挿入
    }

    // BFS開始（queが空になるまで探索を行う）
    while(!que.empty()){
        pair<int,int> v = que.front(); // queから先頭頂点を取り出す
        que.pop();
        x = v.first;
        y = v.second;
        
        // vから辿れる頂点をすべて調べる
        for(auto n:nx){
            int nx_x = x + n.first;
            int nx_y = y + n.second;
            if(nx_x<0 || nx_y<0 || nx_x>=H || nx_y>=W) continue;
            if(C[nx_x][nx_y] == '#') continue; 
            if(seen[nx_x][nx_y]== 0) continue;
            if(seen[nx_x][nx_y]== seen[x][y]) continue;
            if(seen[nx_x][nx_y] != seen[x][y] && seen[nx_x][nx_y] > 0){
                ans = true; 
                return;
            }            
            seen[nx_x][nx_y] = seen[x][y]; // 訪問情報に追加
            que.push({nx_x,nx_y});         // queに挿入
            // cout << nx_x << "," << nx_y << endl;
        }        
    }
    return;
}

int main(){
    cin >> H >> W;
    vector<string> C(H);
    pair<int,int> s;
    rep(i,H){
        cin >> C[i];
        rep(j,W) if(C[i][j]=='S') s={i,j};
    }

    nx[0] = {-1, 0}; // ↑
    nx[1] = { 0, 1};
    nx[2] = { 1, 0};
    nx[3] = { 0,-1};

    // BFS 閉ループがあればtrue
    seen.assign(H,vector<int>(W,-1));
    
    BFS(C,s); // 頂点sを始点としたBFS
    /*
    rep(i,H){
        rep(j,W) cout << seen[i][j] << " ";
        cout << endl;
    } 
    */ 
    cout << (ans?"Yes":"No") << endl;
}
