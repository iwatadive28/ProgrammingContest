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

    vector<int> Ap;
    Ap.push_back(1);
    rep(i,N){
    // for(int i=1;i<N;++i){
        vector<int> A;    
        rep(j,i+1){
            if (j==0 | j==i){
                A.push_back(1);
            }else{
                A.push_back(Ap[j-1]+Ap[j]);
            }
        }

        rep(j,i+1) cout << A[j] << " ";
        cout << endl;
        Ap = A;
    }
}
