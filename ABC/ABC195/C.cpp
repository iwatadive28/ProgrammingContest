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
        n++;
        x/=10;        
    }
    return n;
}

int main(){
    ll N;
    cin >> N;

    ll ans = 0;
    ll add = 0;
    for(int i=1;i<=keta(N);++i){
        if (i%3==1 && i!=1) add++;   
        if(i==keta(N)){
            ans += (N-pow(10,i-1)+1)*add;
            break;
        }else{
            ans += (9*pow(10,i-1))*add;
        }
    }
    
    cout << ans << endl;
}
