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
 
int main(){
     // 入力
    ll N;
    cin >> N;
    vector<ll> C(N);

    rep(i,N) cin >> C[i];
    sort(C.begin(),C.end());
    
    int a;
    cin >> a;
    ll cu = upper_bound(C.begin(),C.end(),a)-C.begin();
    auto iter_u = upper_bound(C.begin(),C.end(),a);
    cout << "upper_bound :"<< cu << ","<< *iter_u <<  endl;
    
    ll cl = lower_bound(C.begin(),C.end(),a)-C.begin();
    auto iter_l = lower_bound(C.begin(),C.end(),a);
    
    cout << "lower_bound :"<< cl << "," << *iter_l <<endl;
    
    return 0;
}