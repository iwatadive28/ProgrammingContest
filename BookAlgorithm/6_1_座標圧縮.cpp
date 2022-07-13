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
const int INF = 20000000;
 
// O(N log N)で座標圧縮する

int main(){
    // INPUT
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    // aをコピーした配列を作ってソートする
    auto b = a;
    b.push_back(INF);
    sort(b.begin(),b.end());

    rep(i,N){
        int res = lower_bound(b.begin(),b.end(),a[i])-b.begin();
        cout << res << endl;
    }

    return 0;
}