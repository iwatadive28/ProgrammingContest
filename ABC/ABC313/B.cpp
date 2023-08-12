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
    vector<int> A(M),B(M);
    rep(i,M){
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
    }

    vector<vector<int>> C(N,vector<int>(0));
    rep(i,M){
        C[B[i]].push_back(A[i]);
    }

    int ans = -1;
    rep(i,N){
        if(C[i].size()==0){
            if(ans==-1) ans = i+1;
            else {
                ans = -1;
                break;
            }
        }        
    }
    cout << ans << endl;
    
}