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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    vector<ll> low(N,0);
    rep(i,N){
        low[i] = A[i]-(i+1);
    }
    vector<ll> ans;
    while(Q--){
        ll k;
        cin >> k;
        // k以上の範囲で最小のインデックスを返す
        int idx = lower_bound(low.begin(),low.end(),k) - low.begin();
        ll tmp;
        if(idx==N){
            tmp = A[N-1] + (k-low[N-1]);
        }else{
            tmp = A[idx] - (low[idx]-k+1);
        }
        ans.push_back(tmp);
    }
    for(auto a:ans) cout << a << endl;
}