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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353; 
const double pi = 3.14159265358979;
/*
*/

int main(){
    int N;
    cin >> N;
    vector<int> a(N),b(N);
    rep(i,N) cin >> a[i];
    rep(i,N) cin >> b[i];

    int MAX = 3000;
    vector<vector<ll>>  dp(N+1,vector<ll>(MAX+1,0));

    dp[0][0] = 1;
    rep(i,N+1){
        rep(j,MAX){
            dp[i][j+1] += dp[i][j]; // 累積和
            dp[i][j+1] %= MOD;
        }
        if(i==N) break;
        for(int j=a[i];j<=b[i];j++){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
        }
    }
    cout << dp[N][MAX] << endl;
}