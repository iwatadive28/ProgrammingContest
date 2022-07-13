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
int func_kj(int x){
    int res = 1;
    rep(i,x){
        res*=(i+1);
    }
    return res;
}

int main(){
    ll P;
    cin >> P;
    map<ll,ll> kj;
    
    rep(i,10) kj[i+1]=func_kj(i+1);
     
    ll ans=0;
    for(int i=10;i>=1;i--){
        while(kj[i]<=P){
            P-=kj[i];
            ans++;
            // printf("ans,i,kj[i],P = %d,%d,%d,%d\n",ans,i,kj[i],P);
        }        
    }    
    cout << ans << endl;
}