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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];
    
    int x,y;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='.'){
                int cnt = 0;
                if(i>0   && S[i-1][j]=='#') cnt++;
                if(i<H-1 && S[i+1][j]=='#') cnt++;
                if(j>0   && S[i][j-1]=='#') cnt++;
                if(j<W-1 && S[i][j+1]=='#') cnt++;

                if(cnt>=2){
                    x = i+1;
                    y = j+1;
                    break;
                }
            }
        }
    }

    cout << x << " " << y << endl;    
}