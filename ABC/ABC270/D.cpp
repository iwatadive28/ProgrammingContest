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
    
    vector<ll> dp(N+1,0); // 持ってる石の数
    
    rep(i,N+1){ // i:残り個数
        rep(j,K){
            if(a[j]>i) continue; // 残り個数より多ければ
            dp[i] = max(dp[i],i-dp[i-a[j]]);
        }
    }

    
    for(auto x:dp) cout << x << " ";
    cout << endl;
    
    cout << dp[N] << endl;
    
}