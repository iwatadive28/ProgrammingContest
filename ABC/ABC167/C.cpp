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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    int N,M,X;
    cin >> N >> M >> X;
    vector<vector<int>> A(N,vector<int>(M,0));
    vector<ll> C(N,0);
    rep(i,N){
        cin >> C[i];
        rep(j,M) cin >> A[i][j];
    }

    int ans = INF;
    // bit全探索
    for (int bit = 0; bit < (1<<N); ++bit) {
        int sum = 0;
        vector<int> D(M,0);
        for (int i=0; i<N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                sum += C[i];
                rep(j,M) D[j] += A[i][j];
            }
        }
        bool ok = true;
        rep(j,M) if(D[j]<X) ok=false;
        if(ok) chmin(ans,sum);
    }

    if(ans == INF) ans = -1;
    cout << ans << endl;

}