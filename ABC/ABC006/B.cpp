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
const ll MOD = 10007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll n;
    cin >> n;
    vector<ll> A(1000000,0);
    
    A[1] = 0;
    A[2] = 0;
    A[3] = 1;
    for(ll i=4;i<=n;i++){
        A[i]=A[i-1]+A[i-2]+A[i-3];
        A[i]%=MOD;
    }
    cout << A[n] << endl;
}