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
int main(){
    vector<string> S(10);
    rep(i,10) cin >> S[i];
    ll a=100,b=-100,c=100,d=-100;

    rep(i,10){
        rep(j,10){
            if(S[i][j]=='#'){
                chmin(a,i+1);
                chmax(b,i+1);
                chmin(c,j+1);
                chmax(d,j+1);
            }
        }
    }

    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
}