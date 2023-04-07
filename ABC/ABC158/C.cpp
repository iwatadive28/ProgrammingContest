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
    int A,B; 
    cin >> A >> B;
    int ans = -1;  
    rep(x,10000) {
        int a = (x+1) *  8 / 100;
        int b = (x+1) * 10 / 100;
        if (a == A && b == B) {
            ans = x+1;
            break;
        }
    }
    cout << ans << endl;
}