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
    vector<string> S;
    rep(i,8){
        string s;
        cin >> s;
        S.push_back(s);
    }

    string ans;
    rep(i,8){
        rep(j,8){
            if(S[i][j]=='*'){
                // cout << i << "," << j << endl;
                ans = ans + (char)('a'+j)+ (char)('8'-i);
            }
        }
    }
    cout << ans << endl;
}