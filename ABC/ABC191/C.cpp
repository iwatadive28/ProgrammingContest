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
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];
    
    ll cnt = 0;
    rep(i,H-1){
        rep(j,W-1){
            ll cb = 0;
            if(S[i  ][j  ] =='#') cb++;
            if(S[i  ][j+1] =='#') cb++;
            if(S[i+1][j  ] =='#') cb++;
            if(S[i+1][j+1] =='#') cb++;

            if (cb==3 || cb==1) cnt++;
        }
    }
    cout << cnt << endl;
}
