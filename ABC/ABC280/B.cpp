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
const ll MOD = 1000000007; //10^9 + 7
/*
*/

int main(){
    int N;
    cin >> N;
    vector<ll> S(N);
    rep(i,N) cin >> S[i];
    
    vector<ll> ans(N);
    ans[0]=S[0];
    for(int i=1;i<N;++i){
        ans[i] = S[i]-S[i-1];
    } 

    for(ll a:ans) cout << a << " ";
    cout << endl;   
}