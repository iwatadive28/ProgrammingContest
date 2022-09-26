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
/*
*/

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i,K) cin >> a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    
    vector<vector<int>> dp(2,vector<int>(N+1,0)); // 持ってる石の数
    
    // 
    rep(j,N+1){ // j:残り個数
        { // i == 0
            int now = 0;
            for(auto x:a){
                if(x<=j) chmax(now,dp[1][j-x]+x);
            }
            dp[0][j] = now;
        }
        { // i == 1
            int now = 1001001001;
            for(auto x:a){
                if(x<=j) chmin(now,dp[0][j-x]);
            }
            dp[1][j] = now;
        }
    }
    /*
    rep(i,2){
        for(auto x:dp[i]) cout << x << " ";
        cout << endl;
    }
    */
    
    cout << dp[0][N] << endl;
    
}