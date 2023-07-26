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
    int N,D;
    cin >> N >> D;
    vector<string> S(N);
    rep(i,N){
        cin >> S[i];
    }
    int ans = 0;
    int cnt = 0;
    rep(j,D){
        bool tmp = true;
        rep(i,N){
            if(S[i][j]=='x') tmp = false;
        }
        if (tmp){
            cnt++;
            chmax(ans,cnt);
        }
        else cnt = 0;
    }
    cout << ans << endl;
}