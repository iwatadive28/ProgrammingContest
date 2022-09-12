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
//
int mymod(int x,int y){
    int res = x%y;
    if(res<0) res+=y;
    return res;
}
int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N) cin >> p[i];

    vector<int> t(3);
    t[0]=-1,t[1]=0;t[2]=1;

    vector<int> q(N,0);
    rep(i,N) rep(j,3) q[mymod(p[i]+t[j]-i,N)]++;
    
    int ans = 0;
    rep(i,N) chmax(ans,q[i]);
    cout << ans << endl;
}