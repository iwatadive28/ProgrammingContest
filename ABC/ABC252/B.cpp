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
int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    int mx = 0;
    rep(i,N){
        cin >> A[i];
        mx = max(A[i],mx);
    }
    set<int> mxA;
    rep(i,N){
        if (A[i]==mx){
            mxA.insert(i+1);
        }
    }

    string ans = "No";
    rep(i,K){
        int B;
        cin >> B;
        if(mxA.count(B)){
            ans = "Yes";
            break;
        }
    }

    cout << ans << endl;
}