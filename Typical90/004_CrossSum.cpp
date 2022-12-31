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
int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>> A(H,vector<int>(W));
    rep(i,H) rep(j,W) cin >> A[i][j];
    
    // 前処理
    vector<int> sumH(H,0),sumW(W,0);
    rep(i,H) rep(j,W) sumH[i] += A[i][j];
    rep(j,W) rep(i,H) sumW[j] += A[i][j];
    
    // 答えの出力
    rep(i,H){
        rep(j,W){
            int ans = sumH[i] + sumW[j] - A[i][j];
            cout << ans << " ";
        }
        cout << endl;
    }
}