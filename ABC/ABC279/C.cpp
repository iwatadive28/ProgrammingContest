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
    int H,W;
    cin >> H >> W;
    vector<string> S(H),T(H);
    rep(i,H) cin >> S[i];
    rep(i,H) cin >> T[i];

    map<string,int> mpS,mpT;
    rep(j,W){
        string s,t;
        rep(i,H){
            s+=S[i][j];
            t+=T[i][j];
        }
        mpS[s]++;
        mpT[t]++;
    }

    bool ans = true;
    for (auto itr = mpS.begin();itr != mpS.end() ; itr++ ){
        string s = itr->first;
        if(mpS[s]!=mpT[s]) ans = false;
    }

    cout << (ans?"Yes":"No") << endl; 
}