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
string dec2a2z(ll x){ // 26進数変換
    string a2z = "";
    while(x>0){
        x--;
        char tmp = 'a'+ x%26;
        a2z = tmp + a2z;
        x /= 26;
    }
    return a2z;
}


int main(){
    ll N;
    cin >> N;

    string ans = dec2a2z(N);
    cout << ans << endl;    
}
