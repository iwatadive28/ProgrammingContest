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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353; //998244353 
const ll INV2 = 499122177; // 2 の逆元
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
ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
       return res;
}

int main(){
    ll N;
    cin >> N;
    
    /*
    f(9) = 9;
    f(99) = 90;
    f(999) = 900;
    f(9999) = 9000;
    f(Nmax) = 9*10^(keta(Nmax)-1);

    f(6)   = 6-0    = 6  -(10^0-1);
    f(16)  = 16-9   = 16 -(10^1-1);
    f(116) = 116-99 = 116-(10^2-1);
    f(N)   = N-(10^keta(N-1)-1);
    */
    
    ll ans = 0;
    rep(i,keta(N)){
        
        ll ne;
        if(i==keta(N)-1){
            ne = N-(mypow(10,i)-1); ne%=MOD;
        }
        else{
            ne = 9*mypow(10,i);ne%=MOD;
        }
        ll sum = ne*(ne+1); sum%=MOD;
        sum*=INV2;          sum%=MOD; 
        ans+=sum;           ans%=MOD;
        // cout << i << ":" << sum << "," << ans << endl;
    }    
    cout << ans << endl;
    // */
}