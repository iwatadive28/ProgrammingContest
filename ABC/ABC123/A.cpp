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
    int a,b,c,d,e,k;
    cin >> a >> b >> c >> d >> e >> k;
    bool ans = true;
    if(b-a>k) ans = false;
    if(c-a>k) ans = false;
    if(d-a>k) ans = false;
    if(e-a>k) ans = false;
    cout << (ans?"Yay!":":(") << endl;
}