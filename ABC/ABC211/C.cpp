#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
string t = "chokudai";
int main(){
    string s;
    cin >> s;
    ll n = s.size();
    ll m = t.size();
    
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    dp[0][0] = 1;
    for(int i=0;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (t[i-1] == s[j-1]){
                dp[i][j] += dp[i-1][j-1];
            }
            dp[i][j] += dp[i][j-1];   
            dp[i][j] %= MOD;         
        }
    }
    /*
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout << dp[i][j] << " ";            
        }
        cout << endl;
    }
    */
    cout << dp[m][n] << endl;
}