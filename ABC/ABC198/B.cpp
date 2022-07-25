#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//
bool kaibun(string s){
    ll M = s.size();
    if(M <= 1)  return true;   
    
    rep(i,M/2){
        if (s[i] != s[M-1-i]) return false;
    }
    return true;
}

int main(){
    string N;
    cin >> N;
    int n = N.size();
    rep(i,n){
        if(N[n-i-1]=='0')  N.pop_back();
        else break;
    }
    // cout << N << endl;

    bool ans = kaibun(N);
    cout << (ans?"Yes":"No") << endl;
}