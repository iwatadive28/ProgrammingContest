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
    string S;
    cin >> S;
    vector<int> C(N,0);
    map<int,string> mp;
    rep(i,N){
        cin >> C[i];
        mp[C[i]].push_back(S[i]);
    }

    vector<int> cnt(M+1,0);
    
    string ans = "";
    rep(i,N){
        int sz = mp[C[i]].size();
        char c = mp[C[i]][(cnt[C[i]]-1+sz)%sz];
        ans.push_back(c);
        cnt[C[i]]++;
    }
    cout << ans << endl;
}
