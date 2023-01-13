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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int solve(int n){
    int ans = 0;
    rep(i,n){
        ll a;
        cin >> a;
        if(a%2==1) ans++;
    }
    // cout << ans << endl;
    return ans ;
}

int main(){
    int T;
    cin >> T;
    vector<int> ans;
    rep(i,T){
        int N;
        cin >> N;
        ans.push_back(solve(N));
    }
    rep(i,T) cout << ans[i] << endl;
}