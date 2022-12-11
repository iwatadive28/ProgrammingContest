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
const ll MOD = 1000000007; //10^9 + 7
/*
*/

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i,M) cin >> A[i];

    vector<int> B(N+1);
    
    // k=1,2,...,Mについて操作を行ったときに、1,2,...,Nがどこに行くのかあらかじめ求める
    iota(B.begin(),B.end(),0);
    for(int i:A){
        swap(B[i],B[i+1]);
    }
    vector<int> pos(N+1);
    for(int i=1;i<=N;i++){
        pos[B[i]] = i;
    }

    iota(B.begin(),B.end(),0);
    for (int i:A){
        if(B[i]==1){
            cout << pos[B[i+1]] << endl;
        }else if(B[i+1]==1){
            cout << pos[B[i]]   << endl;
        }else{
            cout << pos[1] << endl;
        }
        swap(B[i],B[i+1]);
    }
}