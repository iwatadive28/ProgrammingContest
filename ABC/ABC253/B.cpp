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
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];
    
    vector<int> x(2),y(2);
    int k = 0;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='o'){
                x[k] = i;
                y[k] = j;
                k++;
            }
            if (k==2) break;
        }
    }

    int ans = abs(x[1]-x[0]) + abs(y[1]-y[0]);

    cout << ans << endl;
}