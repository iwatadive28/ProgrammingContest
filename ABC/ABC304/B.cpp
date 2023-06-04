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
ll keta(ll x){
   ll n = 0;
   while(x>0){
       n++; x/=10;
   }
   return n;
}

int main(){
    ll N;
    cin >> N;
    ll ans = N;
    if(keta(N)<=3) ans = N;
    else if(keta(N)<=4)  ans = (N/10)     *10;
    else if(keta(N)<=5)  ans = (N/100)    *100;
    else if(keta(N)<=6)  ans = (N/1000)   *1000;
    else if(keta(N)<=7)  ans = (N/10000)  *10000;
    else if(keta(N)<=8)  ans = (N/100000) *100000;
    else if(keta(N)<=9)  ans = (N/1000000)*1000000;

    cout << ans << endl;

}