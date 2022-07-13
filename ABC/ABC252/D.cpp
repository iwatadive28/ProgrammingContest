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
int main(){
    int N;
    cin >> N;
    map<int,int> mp;
    rep(i,N) {
        int a;
        cin >> a;
        mp[a]++;
    }
    
    vector<ll> cnt;
    for(auto itr : mp) cnt.push_back(itr.second);

    ll ms  = cnt.size();
    vector<vector<ll>> dp(3+1,vector<ll>(ms+1,0));
    dp[0][0] = 1; // i:要素数、j:要素の種類
    
    rep(i,4){
        rep(j,ms){
            // 選ばない場合
            dp[i][j+1] += dp[i][j];
            // 選ぶ場合
            if (i+1<4){
                dp[i+1][j+1] += dp[i][j] * cnt[j];
            }
        }
    }
    /*
    rep(i,4){
        rep(j,ms+1){
            cout << dp[i][j] << "," ;
        }
        cout << endl;
    }
    */
    cout << dp[3][ms] << endl;
}