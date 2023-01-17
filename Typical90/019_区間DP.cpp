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
const double pi = 3.14159265359;
/*
//*/
int main(){
    int N;
    cin >> N;
    vector<int> A(2*N);
    rep(i,2*N) cin >> A[i];

    // 区間DP
    // 区間に対する最適な値を、短い区間から求めていく
    vector<vector<ll>> dp(2*N,vector<ll>(2*N,INF));
    rep(i,2*N-1){
        dp[i][i+1] = abs(A[i]-A[i+1]);
    }
    
    // 区間DP
    for(int i=3;i<2*N;i+=2){ // 区間の幅
        rep(j,2*N-i){ // 区間の左端
            int cl = j;   // cl-crの区間について
            int cr = j+i;

            // パターン2: それ以外、kで2つの区間に分けて考えた場合
            for(int k=cl;k<cr-1;k++){
                chmin(dp[cl][cr],dp[cl][k]+dp[k+1][cr]);
            }

            // パターン1：最後に両サイドの人が抜ける場合
            chmin(dp[cl][cr],dp[cl+1][cr-1]+abs(A[cl]-A[cr]));
        }
    }

    cout << dp[0][2*N-1] << endl;
    
}   