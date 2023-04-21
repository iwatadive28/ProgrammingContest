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

int main(){
    ll N;
    cin >> N;
    vector<vector<int>> A(N,vector<int>(N)),B(N,vector<int>(N));
    rep(i,N) rep(j,N) cin >> A[i][j];
    rep(i,N) rep(j,N) cin >> B[i][j];

    bool ans = true;
    rep(i,N) rep(j,N){
        if(A[i][j]!=1) continue;
        if(A[i][j]!=B[i][j]) ans=false;
    }
    if(ans){cout << "Yes" << endl;return 0;}
    
    // 90度
    ans = true;
    rep(i,N) rep(j,N){
        if(A[i][j]!=1) continue;
        int bi = N-j-1;
        int bj = i;        
        if(A[i][j]!=B[bi][bj]) ans=false;
    }
    if(ans){cout << "Yes" << endl;return 0;}

    // 180度
    ans = true;
    rep(i,N) rep(j,N){
        if(A[i][j]!=1) continue;
        int bi = N-i-1;
        int bj = N-j-1;
        if(A[i][j]!=B[bi][bj]) ans=false;
    }
    if(ans){cout << "Yes" << endl;return 0;}

    // 270度
    ans = true;
    rep(i,N) rep(j,N){
        if(A[i][j]!=1) continue;
        int bi = j;
        int bj = N-i-1;
        if(A[i][j]!=B[bi][bj]) ans=false;
    }
    if(ans){cout << "Yes" << endl;return 0;}

    cout << "No" << endl;
}