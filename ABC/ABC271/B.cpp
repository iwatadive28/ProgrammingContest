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
    int N,Q;
    cin >> N >> Q;
    vector<vector<int>> A;
    rep(i,N){
        int l;
        cin >> l;
        vector<int> a(l);
        rep(j,l) cin >> a[j];
        A.push_back(a);
    }

    vector<int> ans(Q);
    rep(i,Q){
        int s,t;
        cin >> s >> t;
        ans[i] = A[s-1][t-1];
    }

    rep(i,Q) cout << ans[i] << endl;
}
