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
ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
     return res;
}

int str2int(string s){
    int res = 0;
    rep(i,s.size()){
        char c = s[s.size()-i-1];
        int tmp = c-'0';
        res += tmp*mypow(10,i);
    }
    return res;
}

int main(){
    string S;
    cin >> S;
    int ans = 1000;
    rep(i,S.size()-2){
        string t = S.substr(i,3);
        chmin(ans,abs(753-str2int(t)));
        // cout << t << "," << ans << endl;
    }
    cout << ans << endl;    
}