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
    string S;
    cin >> S;
    ll ans;
    if     (S=="SUN") ans = 7;
    else if(S=="MON") ans = 6;
    else if(S=="TUE") ans = 5;
    else if(S=="WED") ans = 4;
    else if(S=="THU") ans = 3;
    else if(S=="FRI") ans = 2;
    else if(S=="SAT") ans = 1;

    cout << ans << endl;
}