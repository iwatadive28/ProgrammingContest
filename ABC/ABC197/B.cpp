#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    int H,W,X,Y;
    cin >> H >> W >> X >> Y;
    X--;Y--;
    vector<string> S(H);
    rep(i,H) cin >> S[i];

    int ans = 1;
    // 行をカウント
    for(int i=X+1;i<H;++i){
        if(S[i][Y]=='.') ans++;
        else break;
    }
    for(int i=X-1;i>=0;--i){
        if(S[i][Y]=='.') ans++;
        else break;
    }
    // 列をカウント
    for(int i=Y+1;i<W;++i){
        if(S[X][i]=='.') ans++;
        else break;
    }
    for(int i=Y-1;i>=0;--i){
        if(S[X][i]=='.') ans++;
        else break;
    }
    
    cout << ans << endl;   
}
