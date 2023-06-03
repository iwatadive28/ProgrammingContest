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
    ll X,Y,Z;string S;
    cin >> X >> Y >> Z >> S;
    
    ll N = S.size();
    vector<vector<ll>> dp(N+1,vector<ll>(2,INF));
    dp[0][0] = 0;
    // 配るDP
    rep(i,N){
        int cur;
        if(S[i]=='a') cur = 0; // a
        else          cur = 1; // A

        rep(j,2){     // CPS OFF/ON at i
            rep(k,2){ // CPS OFF/ON at i+1
                ll v = dp[i][j];
                if(j!=k)   v+=Z;
                if(cur==k) v+=X; 
                else       v+=Y;
                chmin(dp[i+1][k],v);
            }
        }
    }
    
    cout << min(dp[N][0],dp[N][1]) << endl;
}