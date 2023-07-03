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

bool is_kaibun(string S){
    string T = S;
    reverse(T.begin(),T.end());
    return (T == S);
}

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S[i];

    bool ans = false;
    rep(i,N){
        rep(j,N){
            if(i==j) continue;
            string tmp = S[i]+S[j];
            if(is_kaibun(tmp)) ans = true;
        }
    }
    cout << (ans?"Yes":"No") << endl;
}