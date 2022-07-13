#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//
const int SIZE = 100005;

vector<int> pfact(int x){
    // O(sqrt(x))
    vector<int> res;
    for (int i=2;i*i<=x;i++){
        if(x%i==0){
            res.push_back(i);
            if (i*i!=x) res.push_back(x/i);
        }
    }
    if(x!=1) res.push_back(x);
    return res;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    
    vector<bool> fl(M+1,true);
    
    // log(N)
    rep(i,N){
        // A[i]の素因数分解をする // sqrt(N)
        vector<int> vec = pfact(A[i]); 
        // 素因数の倍数のフラグを下げる
        for(auto &nx : vec){
            if(fl[nx]){
                for(int j=nx;j<M+1;j+=nx){
                   fl[j] = false;
                }
            }            
        }
    }
    
    vector<int> res;
    for(int i=1;i<=M;i++){
        if(fl[i]) res.push_back(i);
    }

    cout << res.size() << endl;
    for(auto &nx :res) cout << nx << endl;
}