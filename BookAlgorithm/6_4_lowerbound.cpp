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
 
// a以上の範囲で最小の値を示す
int main(){
    // INPUT
    int N,a;
    cin >> N;
    vector<int> b(N);
    rep(i,N) cin >> b[i];    
    cin >> a;
    
    // SORT
    sort(b.begin(),b.end());

    // add INF
    b.push_back(INF);

    // aを固定して解く
    auto iter = lower_bound(b.begin(),b.end(),a);
    int val = *iter;
    cout << val << endl;

    return 0;
}