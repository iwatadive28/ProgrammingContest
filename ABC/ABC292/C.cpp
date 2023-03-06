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
ll cntp(ll x){
    // O(sqrt(x))
    ll res = 0;
    for (int i=1;i*i<=x;i++){
        if(i*i==x) res+=1;
        else if(x%i==0)res+=2;
    }
    return res;
}

int main(){
    ll N;
    cin >> N;

    vector<ll> A(N,0);
    A[1]=1;
    for(ll i=2;i<N;i++){
        // cout << i << "," << cntp(i) << endl;
        A[i] = cntp(i);
    }
    ll ans = 0;
    for(ll i=1;i<N;i++){
        ans += A[i]*A[N-i];
    }
    cout << ans << endl;
}