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
ll H,W;
ll ans = 0;
set<ll> path;
vector<vector<ll>>  A(20,vector<ll>(20,0));
 
void dfs(int x,int y){
    if(path.count(A[x][y])) return;
    path.insert(A[x][y]);

    if(x==H-1 && y==W-1) ans++;
    else{
        if(x!=H-1) dfs(x+1,y);
        if(y!=W-1) dfs(x,y+1);
    }
    path.erase(A[x][y]);
}

int main(){    
    cin >> H >> W;
    rep(i,H) rep(j,W) cin >> A[i][j];
    dfs(0,0);
    cout << ans << endl;
}