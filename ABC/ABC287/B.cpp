#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    int N,M;
    cin >> N >> M;
    vector<string> S(N),T(M);
    rep(i,N) cin >> S[i];
    rep(i,M) cin >> T[i];

    vector<bool> match(N,false);
    rep(i,N){
        string s = S[i].substr(3,6);
        rep(j,M){            
            // cout << t << endl;
            if(s==T[j]) match[i] = true;
        }
    }

    int cnt = 0;
    rep(i,N) if(match[i]) cnt++;
    cout << cnt << endl;
}
