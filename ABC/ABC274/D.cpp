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

ll M = 10000;
int main(){
    ll N,x,y;
    cin >> N >> x >> y;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];

    ll Ny = N/2;
    ll Nx = N-Ny-1;
    vector<vector<bool>> dpx(Nx+1,vector<bool>(2*M+1,false));
    vector<vector<bool>> dpy(Ny+1,vector<bool>(2*M+1,false));
    dpx[0][M+A[0]] = true;
    dpy[0][M]      = true;

    // x
    for(ll i=0;i<Nx;i++){
        ll idx = i*2+2;
        rep(j,2*M+1){
            if(!dpx[i][j]) continue;
            if(j+A[idx]<2*M+1) dpx[i+1][j+A[idx]] = true;
            if(j-A[idx]>=0)    dpx[i+1][j-A[idx]] = true;        
        }
    }

    // y
    for(ll i=0;i<Ny;i++){
        ll idx = i*2+1;
        rep(j,2*M+1){
            if(!dpy[i][j]) continue;
            if(j+A[idx]<2*M+1) dpy[i+1][j+A[idx]] = true;
            if(j-A[idx]>=0)    dpy[i+1][j-A[idx]] = true;        
        }
    }

    if(dpx[Nx][x+M] && dpy[Ny][y+M]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}