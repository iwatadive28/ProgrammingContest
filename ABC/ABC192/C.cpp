#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
ll g1(ll x){
    string s = to_string(x);
    sort(s.begin(),s.end(), greater<int>());
    return stoll(s);
}
ll g2(ll x){
    string s = to_string(x);
    sort(s.begin(),s.end());
    return stoll(s);
}

ll f(ll x){
    return g1(x)-g2(x);
}

int main(){
    ll N,K;
    cin >> N >> K;
    rep(i,K) N = f(N);
    cout << N << endl;
        
}
