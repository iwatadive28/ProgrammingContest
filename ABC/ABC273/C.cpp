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
    ll n;
    cin >> n;
    vector<int> A(n);
    rep(i,n) cin >> A[i];
    vector<int> B = A;
    sort(A.begin(),A.end());
    // 重複を除く
    A.erase(unique(A.begin(), A.end()), A.end());

    vector<int> ans(n,0);
    rep(i,n){
        // A[i]で2文探索
        // A[i]より大きい値のうち、最も小さい値
        int cl = upper_bound(A.begin(),A.end(),B[i])-A.begin();
        int x = A.size()-cl;
        ans[x]++;
        // cout << x << endl;
    }

    rep(i,n){
        cout << ans[i] << endl;
    }
}
