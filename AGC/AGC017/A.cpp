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

ll comb(ll n,ll m){
    ll res = 1;
    rep(i,m){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
     return res;
}

int main(){
    int N,P;
    cin >> N >> P;
    
    vector<ll> A(N,0);
    rep(i,N)cin >> A[i];

    int even = 0, odd = 0;
    rep(i,N){
        if(A[i]%2==0) even++;
        else odd++;
    }

    ll ansP0 = 0;
    for(int i=0;i<=odd;i+=2){
        ansP0 += comb(odd,i);
    }
    ansP0 *= mypow(2,even);

    ll ans = ansP0;
    if(P==1) ans = mypow(2,N) - ansP0;
    cout << ans << endl;
}