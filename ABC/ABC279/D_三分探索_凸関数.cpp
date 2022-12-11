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
    
    ll l = 0;
    ll r = A/B;
    
    // 三分探索
    // 参考：https://qiita.com/ganyariya/items/1553ff2bf8d6d7789127
    while(r-l>2){
        ll m1 = (l*2+r) /3;
        ll m2 = (l+r*2) /3;
        if(f(m1)>f(m2)) l = m1;
        else r = m2;
    }

    double ans = A;
    for (ll i=l;i<=r;i++){
        chmin(ans,f(i));
    }
    cout << fixed << setprecision(10) << ans << endl;
}