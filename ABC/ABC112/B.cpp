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
    int N,T;
    cin >> N >> T;
    vector<pair<int,int>> A(N);
    rep(i,N){
        int c,t;
        cin >> c >> t;
        A[i] = {c,t};
    }
    sort(A.begin(),A.end()); // ,greater<ll>()
    int ans = -1;

    rep(i,N){
        if(A[i].second<=T){
            ans = A[i].first;
            break;
        }
    }
    if(ans!=-1) cout << ans << endl;
    else cout << "TLE" << endl;
    
}