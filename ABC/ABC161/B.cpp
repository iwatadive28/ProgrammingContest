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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    int sum = 0;
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    
    int cnt = 0;
    rep(i,N){
        if(4*M*A[i]>=sum) cnt++;
    }
    
    cout << (cnt>=M?"Yes":"No") << endl;
}