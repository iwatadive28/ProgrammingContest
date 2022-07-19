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
int main(){
    string S;
    cin >> S;
    map<char,int> mp;
    rep(i,S.size()){
        if (mp.find(S[i]) == mp.end()){
            mp[S[i]] = 1;
        }else{
            mp[S[i]]++;
        } 
    }

    for (auto itr = mp.begin();itr != mp.end() ; itr++ ){
        if (itr->second==1){
            cout << itr->first << endl;
            return 0;
        }
    }

    cout << -1 << endl;   
}
