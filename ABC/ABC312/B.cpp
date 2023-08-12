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
    int N,M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    
    vector<pair<int,int>> ans;
    rep(i,N-9+1){
        rep(j,M-9+1){
            bool tmp = true;
            rep(a,3) rep(b,3){
                if(S[i+a][j+b]=='.') tmp = false;
                if(S[i+6+a][j+6+b]=='.') tmp = false;
            }
            rep(a,3){
                if(S[i+a][j+3]=='#') tmp = false;
                if(S[i+6+a][j+5]=='#') tmp = false;
            }
            rep(b,4){
                if(S[i+3][j+b]=='#') tmp = false;
                if(S[i+5][j+5+b]=='#') tmp = false;
            }
            if(tmp) ans.push_back({i+1,j+1});
        }
    }

    for(auto ab:ans){
        cout << ab.first << " " << ab.second << endl;
    }
}