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
    int N,M;
    cin >> N >> M;
    vector<vector<int>>  a(M,vector<int>(N,0));
    rep(i,M) rep(j,N){cin >> a[i][j];a[i][j]--;}

    vector<vector<bool>>  b(N,vector<bool>(N,false));

    rep(i,M){
        rep(j,N-1){
            b[a[i][j]][a[i][j+1]] = true;
            b[a[i][j+1]][a[i][j]] = true;
        }
    }
    /*
    rep(i,N){
        rep(j,N) cout << b[i][j] << " ";
        cout << endl;
    }
    //*/

    int ans = 0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(!b[i][j]) ans++;
        }
    }
    cout << ans << endl;
}