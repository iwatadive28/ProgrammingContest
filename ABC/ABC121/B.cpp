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
    int N,M,C;
    cin >> N >> M >> C;
    vector<int> B(M,0);
    rep(i,M) cin >> B[i];
    
    vector<vector<int>>  A(N,vector<int>(M,0));
    rep(i,N) rep(j,M) cin >> A[i][j];

    int ans = 0;
    rep(i,N){
        int sum = C;
        rep(j,M) sum += B[j]*A[i][j];
        if(sum>0) ans++;
    }
    cout << ans << endl;
}