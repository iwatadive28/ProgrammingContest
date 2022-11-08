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
// const ll MOD = 1000000007; //10^9 + 7
const ll MOD = 998244353; //998244353
/*
*/
map<ll,ll> memo;

ll func(ll k){
    if(k==0) return 1;
    if(memo.find(k) == memo.end()){
        memo[k] = func(k/2) + func(k/3);    
    }    
    return memo[k];
}

int main(){
    ll N;
    cin >> N;
    memo[0] = 1;
    cout << func(N) << endl;
    /*
    for (auto itr = memo.begin();itr != memo.end() ; itr++ ){
        cout << itr->first << "," << itr->second << endl;
    }
    */
}
