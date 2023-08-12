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
bool is_ACGT(char c){
    bool res = false;
    if (c=='A'||c=='C'||c=='G'||c=='T') res = true;
    return res;
}

int main(){
    string S;
    cin >> S;
    
    ll ans = 0;
    ll cur = 0;
    for(char c:S){
        if(is_ACGT(c)) cur++;
        else cur = 0;
        chmax(ans,cur);
    }
    cout << ans << endl;
}