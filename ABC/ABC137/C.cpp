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
    ll N;
    cin >> N;
    string s;    
    map<string,ll> mp;

    while(N--){
        cin >> s;
        sort(s.begin(),s.end());
        mp[s]++;
    }

    ll sum = 0;
    for(auto u : mp){
        if(u.second >=2 ) sum+= u.second * (u.second - 1)/2;
    }
    cout << sum << endl;  
}