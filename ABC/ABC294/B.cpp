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
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    
    rep(i,H){
        rep(j,W){
            char s;
            ll a;
            cin >> a;
            if(a==0) s = '.';
            else s = char('A'+a-1);
            S[i] += s;
        }
    }

    rep(i,H){
        rep(j,W){
            cout << S[i][j];
        }
        cout << endl;
    }
}