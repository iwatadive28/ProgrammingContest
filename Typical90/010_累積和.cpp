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
/*
//*/
int main(){
    int N;
    cin >> N;
    vector<vector<int>> sum(N+1,vector<int>(2,0));
    vector<vector<int>> p(N,vector<int>(2,0));
    rep(i,N){
        int c;cin >> c;
        c--;
        cin >> p[i][c];
    }
    
    // 累積和
    // O(N)
    sum[0][0] = 0;
    sum[0][1] = 0;
    rep(i,N) rep(j,2) sum[i+1][j] = sum[i][j] + p[i][j];

    int Q;
    cin >> Q;
    vector<int> ans1,ans2;
    // O(N)
    rep(i,Q){
        int l,r;
        cin >> l >> r;
        ans1.push_back(sum[r][0]-sum[l-1][0]);
        ans2.push_back(sum[r][1]-sum[l-1][1]);
    }
    rep(i,Q) cout << ans1[i] << " " << ans2[i] << endl;
    // */
}