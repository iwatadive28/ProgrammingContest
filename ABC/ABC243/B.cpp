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
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    
    ll ans1 = 0;
    rep(i,N){
        if (A[i]==B[i]) ++ans1;
    }
    cout << ans1 << endl;

    // ハッシュテーブルに挿入
    set<ll> st;
    rep(i,N){
       if(!st.count(A[i])) st.insert(A[i]);
    }

    ll ans2 = 0;
    rep(i,N){
        if(st.count(B[i])){
            if (A[i]!=B[i]) ++ans2;
        } 
    }
    cout << ans2 << endl;
    return 0;
}

