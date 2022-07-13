#include <iostream>
#include <bits/stdc++.h>
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
    int N,A,B;
    cin >> N >> A >> B;
    vector<vector<char>> X(N*A,vector<char>(N*B));
    
    rep(i,N*A){
        int nr = i/A;
        rep(j,N*B){
            int nc = j/B;
            if ((nr+nc)%2==0)  X[i][j] = '.';
            else               X[i][j] = '#';
        }
    }
  
    rep(i,N*A){
        rep(j,N*B){
            cout << X[i][j] ;
        }
        cout << endl;
    }
}