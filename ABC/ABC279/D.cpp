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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    ll A,B;
    cin >> A >> B;
    
    auto f = [&](ll n) -> double {
        return (double)B*n + (double)A/ sqrt(n+1);
    };
    
    double ans = A;
    ll x = pow((double)A/(B*2), 2./3.) - 1; // 引数がdoubleでないとNG
    // ll x = pow((double)A/(B*2), 2/3) - 1;
    ll l = max(x - 5, 0LL);
    ll r = min(x + 5, A / B);
        
    for(ll n=l;n<=r;n++){
        ans = min(ans,f(n));
    }
    cout << fixed << setprecision(10) << ans << endl;
}