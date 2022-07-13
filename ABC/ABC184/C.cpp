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
int main(){
    ll r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    ll dr = abs(r1-r2);
    ll dc = abs(c1-c2);
    
    ll ans;
    if (dr==0 && dc==0) ans = 0;
    else if(dr == dc)   ans = 1;
    else if(dr+dc<=3)   ans = 1;
    else if(abs(dr-dc)<=3) ans = 2;
    else if((dr+dc)%2==0) ans = 2;
    else if((dr+dc)<=6)   ans = 2;
    else ans = 3;

    cout << ans << endl;
}
