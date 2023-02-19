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

// 4方向を表す 上下左右
int dy[4]={-1, 1, 0, 0};
int dx[4]={ 0, 0,-1, 1};

int main(){
    int H,W;
    cin >> H >> W ;
    vector<string> S(H);
    rep(i,H) cin >> S[i];

    vector<vector<int>>  dist(H,vector<int>(W,-1));
    int ans = -1;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='#') continue;
            // BFS
            queue<pair<int,int>> que;
            vector<vector<int>>  dist(H,vector<int>(W,-1));
            que.push({i,j});
            dist[i][j] = 0;
            int mx = 0;

            while(!que.empty()){
                pair<int,int> v = que.front();
                int y = v.first;
                int x = v.second;

                que.pop();

                // vから1手で行けるマス：ni,nj
                rep(k,4){
                    int ny = y+dy[k];
                    int nx = x+dx[k];

                    if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
                    if(S[ny][nx]=='#') continue;
                    if(dist[ny][nx]!=-1) continue;

                    dist[ny][nx] = dist[y][x] + 1;
                    que.push({ny,nx});
                    chmax(mx,dist[ny][nx]);
                }
            }
            
            chmax(ans,mx);
        }
    }

    cout << ans << endl;
}