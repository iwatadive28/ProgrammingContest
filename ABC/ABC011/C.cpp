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
    int N,NG1,NG2,NG3;
    cin >> N >> NG1 >> NG2 >> NG3;
    set<int> st;
    st.insert(NG1);
    st.insert(NG2);
    st.insert(NG3);
    
    vector<int> dp(N+1,-1);
    if(!st.count(N)) dp[N]=100;

    for(int i=N;i>0;i--){
        if(dp[i]<0) continue;
        if(!st.count(i-1))           chmax(dp[i-1],dp[i]-1);
        if(i-2>=0 && !st.count(i-2)) chmax(dp[i-2],dp[i]-1);
        if(i-3>=0 && !st.count(i-3)) chmax(dp[i-3],dp[i]-1);
    }

    // rep(i,N+1) cout << dp[i] << " ";
    // cout << endl;

    cout << (dp[0]>=0?"YES":"NO") << endl;    
}