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
    ll N,M;
    cin >> N >> M;
    
    vector<bool> AC(N+1,false);
    vector<ll>   NG(N+1,0);
    
    rep(i,M){
        ll p; 
        string s;
        cin >> p >> s;
        if(AC[p]) continue;

        if(s=="AC") AC[p] = true;
        else        NG[p]++;
    }

    ll cntAC = 0;
    ll cntNG = 0;
    rep(i,N+1){
        if(AC[i]){
            cntAC++;
            cntNG+= NG[i];
        }
    }
    cout << cntAC << " " << cntNG << endl;
}       
