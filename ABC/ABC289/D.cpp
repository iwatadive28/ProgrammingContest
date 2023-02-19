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
    int N;
    cin >> N;    
    vector<int> A(N);
    rep(i,N) cin >> A[i];   
    
    int M;
    cin >> M;
    vector<int> B(M,0);
    rep(i,M) cin >> B[i];

    int X;
    cin >> X;
    
    vector<bool> mochi(X,false);
    rep(i,M) mochi[B[i]] = true;

    vector<bool> dp(X+1,false);
    dp[0] = true;

    rep(i,X){
        if(!dp[i]) continue;
        rep(j,N){
            int nx = i+A[j];
            if(nx<=X && !mochi[nx]) dp[nx] = true;
        }
    }


    cout << (dp[X]?"Yes":"No") << endl;
}