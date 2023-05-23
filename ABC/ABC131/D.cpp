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
    int N;
    cin >> N;
    vector<pair<int,int>> ba(N);
    rep(i,N){
        int a,b;
        cin >> a >> b;
        ba[i] = {b,a};
    }
    sort(ba.begin(),ba.end()); // ,greater<ll>()

    bool ans = true;
    int now = 0;
    rep(i,N){
        now+=ba[i].second;
        if(now>ba[i].first) ans = false;
        // cout << now << endl;
    }
    cout << (ans?"Yes":"No") << endl;
}