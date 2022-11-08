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
int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N) cin >> p[i];
    
    int cnt = 0;
    do {
        if(cnt==1) break;
        cnt ++;
    } while (prev_permutation(p.begin(), p.end()));

    rep(i,N) cout << p[i] << " ";
    cout << endl; 
    
}
