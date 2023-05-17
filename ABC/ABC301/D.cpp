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
    ll N;
    cin >> S >> N;
    ll ans = -1;
    
    reverse(S.begin(),S.end());
    while(S.size()<60) S.push_back('0');
    int lb =-1;
    for (ll i=0; i<60; i++){
        if (S[i] != '?' and S[i] - '0' != (N >> i & 1)) lb = i;
    }

    if(lb==-1){
        cout << N << endl;
        return 0;
    }

    for (ll i=lb; i<60; i++){
        if(S[i]=='1' or !(N>>i&1)) continue;
        S[i] = '0';
        for (ll j=0; j<i; j++){
            if(S[j]=='?') S[j]='1';
        }
        for (ll j=i+1; j<60; j++){
            S[j]='0'+(N>>j&1);
        }
        ll ans = 0;
        for (ll j=59; j>=0; j--){
            ans *= 2;
            ans += S[j]-'0';
        }
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
}