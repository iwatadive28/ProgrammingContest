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
    ll M = keta(N);
    
    // O(2^18=262144)
    ll ans = INF;
    for(int bit=0;bit<(1<<M);++bit){
        ll tmp = N;
        ll cnt = 0;
        ll num = 0;
        ll kt  = 1;
        rep(i,M){
            if(bit&(1<<i)){
                // cout << tmp%10 << endl;
                num += (tmp%10)*kt;
                kt *=10;
            }
            else cnt++;
            tmp/=10;            
        } 
        // cout << bit << "," << num << endl;
        if(num!=0 & num%3==0) chmin(ans,cnt);
    }
    if(ans==INF) ans = -1;
    cout << ans << endl;
}
