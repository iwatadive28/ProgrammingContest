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
    string  S;
    cin >> S;

    int ans;
    if    (S=="tourist")   ans = 3858;
    else if(S=="ksun48")    ans = 3679;
    else if(S=="Benq")      ans = 3658;
    else if(S=="Um_nik")    ans = 3648;
    else if(S=="apiad")     ans = 3638;
    else if(S=="Stonefeang")ans = 3630;
    else if(S=="ecnerwala") ans = 3613;
    else if(S=="mnbvmar")   ans = 3555;
    else if(S=="newbiedmy") ans = 3516;
    else if(S=="semiexp")   ans = 3481;

    cout << ans << endl;
}