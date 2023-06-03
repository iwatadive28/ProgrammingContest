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
    int N,S;
    cin >> N >> S;
    vector<int> a(N),b(N);
    rep(i,N) cin >> a[i] >> b[i];

    vector<vector<bool>>  dp(N+1,vector<bool>(S+1,false));
    dp[0][0] = true;
    rep(i,N){
        rep(j,S+1){
            if(!dp[i][j]) continue;
            if(j+a[i]<=S) dp[i+1][j+a[i]] = true;
            if(j+b[i]<=S) dp[i+1][j+b[i]] = true;
        }
    }
    
    if(!dp[N][S]){
        cout << "No" << endl;
        return 0;
    }
    
    string ans(N,'H');
    for(int i=N-1; i>=0; --i){
        if(S>=a[i] && dp[i][S-a[i]]){
            ans[i] = 'H';
            S-=a[i];
        }else{
            ans[i] = 'T';
            S-=b[i];
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;

}