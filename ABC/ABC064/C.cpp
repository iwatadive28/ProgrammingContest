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
/*
g0 レート 1-399：灰色
g1 レート 400-799：茶色
g2 レート 800-1199：緑色
g3 レート 1200-1599：水色
g4 レート 1600-1999：青色
g5 レート 2000-2399：黄色
g6 レート 2400-2799：橙色
g7 レート 2800-3199：赤色
g8 3200以上
*/
int rating(int x){
    int y = x/400;
    if(y>=8) y=8;    
    return y;
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    
    vector<bool> color(8,false);
    int cnt = 0; // 3200以上のレートをカウント    
    rep(i,N){
        int clr = rating(a[i]);
        if (clr==8) cnt++;
        else color[clr] = true;
    }

    int ans = 0;
    rep(i,8) if(color[i]) ans++;
    
    int ans_min = max(1,ans);
    int ans_max = ans + cnt;
    cout << ans_min << " "<< ans_max << endl;
    
}
