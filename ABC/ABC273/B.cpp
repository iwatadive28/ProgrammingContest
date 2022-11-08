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
ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
    return res;
}

ll func(ll x,int now, ll k){
    ll res = x;
    while (now<k){
        int n = (res%(mypow(10,now+1)))/mypow(10,now);
        
        if(n<5) res = res-res%(mypow(10,now+1));
        else    res = res-res%(mypow(10,now+1))+mypow(10,now+1);
        // cout << n << "," << res << endl;
        now++;
    }
    return res;
}

int main(){
    ll x,k;
    cin >> x >> k;
    cout << func(x,0,k) << endl;
}