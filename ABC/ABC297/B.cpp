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
    string S;
    cin >> S;
    vector<ll> B,R,K;
    
    rep(i,8){
        if(S[i]=='R') R.push_back(i);
        if(S[i]=='B') B.push_back(i);
        if(S[i]=='K') K.push_back(i);
    }
    bool ans = true;
    if(B[0]%2==B[1]%2) ans = false;
    if(R[0]>K[0] || R[1]<K[0]) ans = false;
    cout << (ans?"Yes":"No") << endl;
}