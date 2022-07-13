#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//
const ull M    = 998244353;
const ull inv2 = 499122177;
// using mint=modint998244353;

ll keta(ll n){
    ll keta = 0;
    while( n!=0 ){
        n = n/10;
        keta++;
    }
    return keta;
}

int main(){
    ull N;
    cin >> N;
    
    ull ans = 0;
    
    rep(i,keta(N)){
        ull ne = (pow(10,i+1) - pow(10,i));
        if (i==keta(N)-1){
            ne = N - pow(10,i)+1;
        }
        ne %= M;
        ull sum = ((1+ne)*ne)%M;
        sum = (sum * inv2)%M;
        ans += sum;
        ans %= M;
        // cout << i <<","<< 1 << ","<< ne << "," << sum << "," << ans << endl;
    }
    
    cout << ans << endl;    
}