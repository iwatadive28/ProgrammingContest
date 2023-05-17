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
ll A,B,X;

ll keta(ll x){
   ll n = 0;
   while(x>0){
       n++; x/=10;
   }
   return n;
}

ll func(ll n){
    ll res = A*n+B*keta(n);
    return res;
}

int main(){
    cin >> A >> B >> X;
    
    // 二分探索
    ll ok = 0;
    ll ng = 1000000001;
    while(ok+1!=ng){
        ll mid=(ok+ng)/2;
        if(func(mid)<=X) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}