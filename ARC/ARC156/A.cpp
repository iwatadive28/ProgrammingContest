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

ll solve(){
    ll res = 0;    
    ll N;
    string S;
    cin >> N >> S;

    int one = count(S.begin(), S.end(), '1');
    if(one==0) return 0;
    if(one%2==1) return -1;
    bool adj = false; // 隣接しているか？
    rep(i,N-1) if(S[i]=='1' && S[i+1]=='1') adj = true;

    if(one!=2 || !adj) return one/2;
    if(N==3) return -1;
    if(N==4 && S=="0110") return 3;
    return 2;
}

int main(){
    ll T;   
    cin >> T;
    vector<ll> ans;
    rep(i,T) ans.push_back(solve());
    rep(i,T) cout << ans[i] << endl;
}