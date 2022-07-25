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
    int N;
    cin >> N;
    vector<string> A(N);
    rep(i,N) cin >> A[i];
    string ans = "correct";
    rep(i,N){
        rep(j,N){
            if(i==j) continue;
            if(A[i][j]=='W' && A[j][i] !='L'){
                ans = "incorrect";
                break;
            }
            if(A[i][j]=='L' && A[j][i] !='W'){
                ans = "incorrect";
                break;
            }
            if(A[i][j]=='D' && A[j][i] !='D'){
                ans = "incorrect";
                break;
            }            
        }
    }

    cout << ans << endl;   
}
