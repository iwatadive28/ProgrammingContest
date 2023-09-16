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
const double pi = 3.14159265358979;
/*
*/

int main(){
    int N,T,A;
    cin >> N >> T >> A;
    vector<int> H(N,0);
    rep(i,N) cin >> H[i];
    A*=1000,T*=1000;
    int ans = 0;
    int mn  = INF;
    rep(i,N){
        int tmp = T-H[i]*6;
        if(chmin(mn,abs(A-tmp))) ans = i+1;
    }
    cout << ans << endl;
}