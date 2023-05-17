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
    int H,W;
    cin >> H >> W;
    vector<string> A(H),B(H);
    rep(i,H) cin >> A[i];
    rep(i,H) cin >> B[i];

    bool ans = false;
    rep(s,H) rep(t,W){
        bool tmp = true;
        rep(i,H) rep(j,W){
            if(A[(i+s)%H][(j+t)%W] != B[i][j]) tmp = false;
        }
        if(tmp) ans = true;
    }
    cout << (ans?"Yes":"No") << endl;    
}