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
    ll R,C;
    cin >> R >> C;
    vector<string> B(R);
    rep(i,R) cin >> B[i];
    vector<string> A = B;

    rep(i,R){
        rep(j,C){
            if(B[i][j]=='.'||B[i][j]=='#') continue;
            int n = int(B[i][j]-'0');
            
            rep(x,R){
                rep(y,C){
                    int r = abs(x-i)+abs(y-j);
                    if(r<=n){
                        A[x][y] = '.';
                    }
                }
            }            
        }
    }

    rep(i,R) cout << A[i] << endl;
}