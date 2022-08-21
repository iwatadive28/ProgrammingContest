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
//
int main(){
    int H,W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i,H) cin >> G[i];

    vector<vector<bool>> seen(H,vector<bool>(W,false));
    int i=0,j=0;
    while(true){
        if(seen[i][j]) break;
        
        int ni = i;
        int nj = j;
        // cout << i << "," << j << ":" << G[i][j] <<",";
        if     (G[i][j] == 'U') ni = i-1; 
        else if(G[i][j] == 'D') ni = i+1;
        else if(G[i][j] == 'L') nj = j-1;
        else if(G[i][j] == 'R') nj = j+1;
        
        // cout << ni << "," << nj << endl;
        if((ni<0||ni>=H) || (nj<0||nj>=W)) break;
        seen[i][j] = true;
        i = ni;
        j = nj;
    }

    if(seen[i][j]) cout << -1 << endl;
    else           cout << i+1 << " " << j+1 << endl;
}
