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
//

ll maxnum(vector<int> vec){
    ll res = 0;
    int N = vec.size();
    rep(i,N){
        ll tmpr = 0;
        ll tmpl = 0;
        rep(j,N){
            tmpr += vec[(i+j)%N]   * pow(10,j);
            tmpl += vec[(i-j+N)%N] * pow(10,j);
        }
        res = max(res,tmpr);
        res = max(res,tmpl);        
    }
    return res;

}

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    vector<vector<ll>> A(N,vector<ll>(N));
    
    rep(i,N){
        string s;
        cin >> s;
        rep(j,N){
            A[i][j] = s[j] - '0';
        }
    }
    
    ll ans = 0;
    // 横
    rep(i,N){
        vector<int> tmp(N);
        rep(j,N) tmp[j] = A[i][j];
        ans = max(ans,maxnum(tmp));
    }
    
    // 縦
    rep(j,N){
        vector<int> tmp(N);
        rep(i,N) tmp[i] = A[i][j];
        ans = max(ans,maxnum(tmp));
    }
    
    // 斜め
    rep(i,N){
        vector<int> tmp(N);
        rep(j,N) tmp[j] = A[(i+j)%N][j];
        ans = max(ans,maxnum(tmp));
    }
    
    // 斜め
    rep(i,N){
        vector<int> tmp(N);
        rep(j,N) tmp[j] = A[(i-j+N)%N][j];
        ans = max(ans,maxnum(tmp));
    }
    
    cout << ans << endl;
}
