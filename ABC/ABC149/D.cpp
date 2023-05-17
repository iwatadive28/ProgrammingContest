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
    int N,K,R,S,P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    
    map<char,pair<char,int>> mp;
    mp['r']={'p',P};
    mp['s']={'r',R};
    mp['p']={'s',S};
    
    vector<char> Q(N);
    int ans = 0;
    rep(i,N){
        if(i-K>=0&&Q[i-K]==mp[T[i]].first){
            if(i+K<N && T[i+K]!=T[i]) Q[i]=T[i+K];
            else                      Q[i]=T[i];
            continue;
        }
        Q[i]=mp[T[i]].first;
        ans += mp[T[i]].second;
    }
    // cout << Q << endl;
    cout << ans << endl;
}