#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<ll> X(N);
    rep(i,N) cin >> X[i];
    
    vector<int> A(N-1),B(N-1);
    vector<int> V(Q),K(Q);
    
    rep(i,N-1){
        cin >> A[i] >> B[i];
    }
    rep(i,Q){
        cin >> V[i] >> K[i];
    }
    
    auto cmp = [&](int x, int y) -> bool {
        return X[x] > X[y];
    };
    // SORT
    stable_sort(X.begin(), X.end(), cmp);
    
    // output
    rep(i,Q){
        vector<ll> vec = X;
        sort(vec.begin(),vec.end());
        cout << vec[K[i]-1] << endl;
    }
    return 0;
}