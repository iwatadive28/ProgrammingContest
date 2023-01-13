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
//*/

int main(){
    ll N,A,B,C;
    cin >> N >> A >> B >> C;
    // 工夫して全探索
    ll ans = 9999;
    ll L = 9999;

    for(ll x=0;x<=L;++x){
        for(ll y=0;x+y<=L;++y){
            if(N-A*x-B*y<0) continue;
            if((N-A*x-B*y)%C==0){ // x,yからzは一意に求まる
                ll z = (N-A*x-B*y)/C;
                chmin(ans,x+y+z);                
            }            
        }
    }       
    
    cout << ans << endl;

}   