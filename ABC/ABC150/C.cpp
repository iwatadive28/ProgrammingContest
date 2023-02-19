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
bool is_same_vec(vector<int> A,vector<int> B){
    if(A.size()!=B.size()) return false;
    bool res = true;
    rep(i,A.size()){
        if(A[i]!=B[i]) res = false;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    vector<int> P(N),Q(N);
    rep(i,N) cin >> P[i];
    rep(i,N) cin >> Q[i];

    vector<int> A(N);
    rep(i,N) A[i] = i+1;

    int a,b;
    int n=0;
    do {
        n++;
        if(is_same_vec(A,P)) a = n;
        if(is_same_vec(A,Q)) b = n;
    } while (next_permutation(A.begin(), A.end()));
    
    cout << abs(a-b) << endl;
}
