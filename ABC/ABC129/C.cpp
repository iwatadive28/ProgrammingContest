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
    int N,M;
    cin >> N >> M;
    set<int> st;
    rep(i,M){
        int a;
        cin >> a;
        st.insert(a);
    }

    vector<int> dp(N+1,0);
    dp[0] = 1;
    rep(i,N){
        if(i+1<=N && !st.count(i+1)){
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
        }
        if(i+2<=N && !st.count(i+2)){
            dp[i+2] += dp[i];
            dp[i+2] %= MOD;
        }
    }    
    cout << dp[N] << endl;

}