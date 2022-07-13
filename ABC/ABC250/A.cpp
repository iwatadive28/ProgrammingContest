#include <iostream>
#include <bits/stdc++.h>
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
    int H,W,R,C;
    cin >> H >> W >> R >> C;
    
    //
    int cnt = 0;
    // 上
    if ( H>1 & R>1 ) cnt++;
    // 下
    if ( H!=R) cnt ++;
    // 右
    if ( C!=W ) cnt++;
    // 左
    if ( W>1 & C>1 ) cnt++;
    
    cout << cnt << endl;  
}