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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
/*
*/
bool kaibun(string s){
    ll M = s.size();
    if(M <= 1)  return true;   
    
    rep(i,M/2){
        if (s[i] != s[M-1-i]) return false;
    }
    return true;
}

int main(){
    string S;
    cin >> S;
    int N = S.length();
    bool ans = false;
    if(kaibun(S) && kaibun(S.substr(0,N/2)) && kaibun(S.substr(N/2+1,N))){
        ans = true;
    }
    cout << (ans?"Yes":"No") << endl;
}