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
int di[4]={-1, 1, 0, 0};
int dj[4]={ 0, 0,-1, 1};

vector<vector<bool>> stop;
vector<vector<bool>> pass;
vector<string> S;

void dfs(int i,int j){
    if(stop[i][j]) return;
    stop[i][j] = true;
    rep(x,4){
        int ii=i,jj=j;
        while (S[ii+di[x]][jj+dj[x]]=='.'){
            ii += di[x];
            jj += dj[x];
            pass[ii][jj] = true;
        }
        dfs(ii,jj);
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    S.assign(N,"");
    rep(i,N) cin >> S[i];

    stop.assign(N,vector<bool>(M,false));
    pass.assign(N,vector<bool>(M,false));
    
    pass[1][1] = true;
    dfs(1,1);

    int ans = 0;
    rep(i,N)rep(j,M){
        if(pass[i][j]) ans++;
    }
    cout << ans << endl;
}