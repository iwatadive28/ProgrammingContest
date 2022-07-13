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

int main(){
    // INPUT
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    for(ll i=1;i<N;++i){
        ll pos = i;
        while(pos!=0 && a[pos-1]>a[pos]){
            swap(a[pos-1],a[pos]);
            --pos;
        }
        output(a);
    }

    return 0;
}