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
    vector<int> L(N,0);
    int sum = 0;
    rep(i,N){
        cin >> L[i];
        sum += L[i];
    }
    sort(L.begin(),L.end()); // ,greater<ll>()
    bool ans = false;
    if(L[N-1]<sum-L[N-1]) ans = true;
    cout << (ans?"Yes":"No") << endl;
}