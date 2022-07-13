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
    int N,X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i,N) {
        cin >> A[i];
        if (i%2==1) A[i]--;
    }

    string ans = "Yes";
    rep(i,N){
        X-=A[i];
        //cout << "i,X,A[i] = " << i << "," << X << "," << A[i] << endl;
        if(X<0) {
            ans = "No";
            break;
        }
    }
    
    cout << ans << endl;
}