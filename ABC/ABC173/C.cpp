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

int main(){
    int H,W,K;
    cin >> H >> W >> K;
    vector<string> c(H);
    rep(i,H) cin >> c[i];

    int ans = 0;
    rep(mH,1<<H){
        rep(mW,1<<W){
            vector<string> c2 = c;
            rep(i,H){
                if(mH&(1<<i)) rep(j,W) c2[i][j]='R';
            }
            rep(j,W){
                if(mW&(1<<j)) rep(i,H) c2[i][j]='R';
            }

            int cnt = 0;
            rep(i,H){
                rep(j,W){
                    if (c2[i][j]=='#') cnt++;
                }
            }
            if(cnt==K) ans++;
        }
    }
    cout << ans << endl;
}