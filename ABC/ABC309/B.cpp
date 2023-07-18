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
    int N;
    cin >> N;
    vector<string>  A(N);
    rep(i,N) cin >> A[i];
    vector<string> B = A;
    
    for(int j=1;j<N;j++){
        B[0][j] = A[0][j-1];
    }
    for(int i=1;i<N;i++){
        B[i][N-1] = A[i-1][N-1];
    }
    for(int j=N-2;j>=0;j--){
        B[N-1][j] = A[N-1][j+1];
    }
    for(int i=N-2;i>=0;i--){
        B[i][0] = A[i+1][0];
    }

    
    rep(i,N){
        rep(j,N){
            cout << B[i][j];
        }
        cout << endl;
    }
    
}