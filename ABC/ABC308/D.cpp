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

string snuke = "snuke";


int main(){
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];

    map<char,int> mp;
    mp['s']=0;
    mp['n']=1;
    mp['u']=2;
    mp['k']=3;
    mp['e']=4;

    vector<vector<bool>> visit(H,vector<bool>(W,false));
    queue<pair<int,int>> que;
    
    if(S[0][0] == 's'){
        que.push({0,0});
        visit[0][0] = true;
    }    
    while(!que.empty()){
        pair<int,int> v = que.front();
        que.pop();
        int y = v.first;
        int x = v.second;
        int now = mp[S[y][x]];
        
        
        // vから1手で行けるマス：ni,nj
        rep(k,4){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
            if(S[ny][nx]!=snuke[(now+1)%5]) continue;
            if(visit[ny][nx]) continue;
            que.push({ny,nx});
            visit[ny][nx] = true;
        }
    }

    cout << (visit[H-1][W-1]?"Yes":"No") << endl;
}