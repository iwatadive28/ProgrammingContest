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
    vector<vector<int>> A(3,vector<int>(3));
    rep(i,3) rep(j,3) cin >> A[i][j];

    int N;
    cin >> N;
    vector<int> b(N);
    rep(i,N) cin >> b[i];

    vector<vector<bool>> C(3,vector<bool>(3,false));

    rep(i,3) rep(j,3) rep(k,N) if(b[k]==A[i][j]) C[i][j] = true;
    
    /*
    rep(i,3){
        rep(j,3) cout << C[i][j] << " ";
        cout << endl;
    }
    */
    bool ans = false;
    rep(i,3) if(C[i][0] && C[i][1] && C[i][2]) ans = true;
    rep(j,3) if(C[0][j] && C[1][j] && C[2][j]) ans = true;
    if(C[0][0] && C[1][1] && C[2][2]) ans = true;
    if(C[2][0] && C[1][1] && C[0][2]) ans = true;

    cout << (ans?"Yes":"No") << endl;
}

