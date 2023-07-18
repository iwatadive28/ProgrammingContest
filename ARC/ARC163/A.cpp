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
string solve(){
    string res = "No";
    int N;
    string S;
    cin >> N >> S;
    for(int i=1;i<N;++i){
        string t0 = S.substr(0,i);
        string t1 = S.substr(i,N-i);
        if(t0<t1) res = "Yes";
        // cout << t0 << " " << t1 << endl;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    vector<string> ans(T);
    rep(i,T){
        ans[i] = solve();
    }
    for(auto a:ans) cout << a << endl;
}