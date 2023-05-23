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
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    sort(S.begin(),S.end());

    bool ans = false;
    do {
        bool tmp = true;
        rep(i,N-1){            
            int diff = 0;
            rep(j,M) if(S[i][j]!=S[i+1][j]) diff++;
            if(diff!=1) tmp = false;       
        }
        if(tmp) ans = true;     
    } while (next_permutation(S.begin(),S.end()));

    cout << (ans?"Yes":"No") << endl;
}