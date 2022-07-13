#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//

int main(){
    // INPUT
    ll N;
    cin >> N;

    vector<ll> A(N),B(N),sum(N);
    vector<string> S(N);
    
    rep(i,N){
        cin >> S[i] >> A[i] >> B[i];
        sum[i] = A[i]+B[i];
    } 
    
    // index
    vector<ll> idx(N);
    rep(i,N) idx[i] = i;
    
    // sumを比較して安定ソートを使う
    // 小さい順に出力
    auto cmpsum = [&](int x, int y) -> bool {
        return sum[x] < sum[y];
    };
    // SORT
    stable_sort(idx.begin(), idx.end(), cmpsum);

    // Aを比較して安定ソートを使う
    auto cmpA = [&](int x, int y) -> bool {
        return A[x] > A[y];
    };
    // SORT
    stable_sort(idx.begin(), idx.end(), cmpA);

    // Output
    rep(i,N) {
        cout << S[idx[i]] << " " << A[idx[i]] << " " << B[idx[i]] << endl;
    }
    return 0;
}