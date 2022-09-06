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
//
int main(){
    map<string,int> mp;
    // Monday, Tuesday, Wednesday, Thursday, Friday
    mp["Monday"]    = 5;
    mp["Tuesday"]   = 4;
    mp["Wednesday"] = 3;
    mp["Thursday"]  = 2;
    mp["Friday"]    = 1;
    
    string S;
    cin >> S;
    
    cout << mp[S] << endl;
}
