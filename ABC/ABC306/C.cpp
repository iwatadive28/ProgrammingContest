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
    ll N;
    cin >> N;
    vector<vector<ll>> f2(N);
    rep(i,3*N){
        int a;
        cin >> a;
        a--;
        f2[a].push_back(i+1);
    }
    vector<pair<int,int>> f(N);
    rep(i,N) f[i] = {f2[i][1],i+1};
    sort(f.begin(),f.end()); // ,greater<ll>()
    
    for(auto a:f) cout << a.second << " ";
    cout << endl;
}