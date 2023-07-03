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
    int N,M;
    cin >> N >> M;
    vector<vector<int>> S(M);
    rep(i,M){
        int k;
        cin >> k;
        rep(j,k){
            int s; cin >> s;s--;
            S[i].push_back(s);
        }
    }
    vector<int> P(M);
    rep(i,M) cin >> P[i];

    int ans = 0;
    rep(msk,1<<N){
        int ok = 0;
        rep(m,M){
            int cnt = 0;
            for(auto s:S[m]) if(msk&(1<<s)) cnt++;
            if (cnt%2 == P[m]) ok++;
        }
        if(ok==M) ans++;
    }
    cout << ans << endl;
}