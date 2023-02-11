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
// 素因数列挙
// エラトステネスの篩（ふるい）
int main(){
    ll N,K;
    cin >> N >> K;

    // 素因数をカウント
    // O(NlogN)
    vector<ll> c(N+1,0);
    for (ll i=2; i<=N; i++){
        if(c[i]>=1) continue;
        for (ll j=i; j<=N; j+=i) c[j]++; 
    }

    
    ll ans = 0;
    for (ll i=2; i<=N; i++){
        if(c[i]>=K) ans++;
    }

    cout << ans << endl;

}
