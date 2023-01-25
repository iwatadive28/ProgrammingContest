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
    int N;
    cin >> N;
    vector<int> lx(N),ly(N),rx(N),ry(N);
    rep(i,N) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];

    // 領域加算 二次元 いもす法
    // 加算領域端に(1,-1)を代入
    vector<vector<int>> A(1010,vector<int>(1010,0));
    rep(i,N){
        A[lx[i]][ly[i]] += 1;
        A[rx[i]][ly[i]] +=-1;
        A[lx[i]][ry[i]] +=-1;
        A[rx[i]][ry[i]] += 1;
    }

    // 累積和
    // X軸方向に累積和
    for(int i=0;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            A[i][j] += A[i][j-1];
        }
    }

    // Y軸方向に累積和
    for(int i=1;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            A[i][j] += A[i-1][j];
        }
    }

    // 領域をカウントする
    vector<int> ans(N+1);
    rep(i,1001){
        rep(j,1001){
            ans[A[i][j]]++;
        }
    }

    // 出力
    rep(i,N) cout << ans[i+1] << endl;
}