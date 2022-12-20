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
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool inc    = false; // 括られているときはTrue
    bool komoji;
    string ans = S;
    rep(i,S.size()){
        if(S[i]=='"'){
            if(inc) inc = false;
            else    inc = true;
        }
        if ('a'<=S[i] & S[i]<='z') komoji  = true; 
        else                       komoji  = false;

        if(!inc && !komoji && S[i]!='"') ans[i] = '.';
    }
    cout << ans << endl;


}