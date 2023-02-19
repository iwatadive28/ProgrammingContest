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

bool alltrue(vector<bool> V){
    bool res = true;
    for(bool a:V) if(!a) res = false;
    return res;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>>  a(M,vector<int>(0));
    vector<int> C(M);
    
    rep(i,M){
        cin >> C[i];
        rep(j,C[i]){
            int t;
            cin >> t;
            a[i].push_back(t);
        }
    }

    int ans = 0;
    // bit全探索
    for (int bit = 0; bit < (1<<M); ++bit) {
        vector<bool> B(N,false);
        for (int i = 0; i < M; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                rep(j,C[i]) B[a[i][j]-1] = true;
            }
        }
        if (alltrue(B)) ans++;

        // cout << bit <<  ":";
        // cout << alltrue(B) << endl;
    }

    cout << ans << endl;
}