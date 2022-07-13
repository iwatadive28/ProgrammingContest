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
void output(vector<ll> a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
    return;
}

// クイックソート
int main(){
    // INPUT
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    vector<ll> L,R;
    ll x = N/2;
    rep(i,N){
        // 1. i=X ならば何も行わない。
        if (i==x){

        }
        // 2. i!=X かつ A[i]<A[X] ならば A[i] を L の末尾に追加する。
        else if(a[i]<a[x]){
            L.push_back(a[i]);
        }
        // 3. i!=X かつ A[i]≥A[X] ならば A[i] を R の末尾に追加する。
        else if(a[i]>=a[x]){
            R.push_back(a[i]);
        }
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());

    L.insert(L.end(),a[x]);
    L.insert(L.end(),R.begin(),R.end());
    output(L);
    return 0;
}