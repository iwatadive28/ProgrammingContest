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
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    //
    bool sort = true;
    while(sort){
        // ソート必要だったかどうかフラグを立てる
        bool sort_tmp = false;
        rep(i,N-1){
            if (a[i] > a[i+1]){
                swap(a[i],a[i+1]);
                sort_tmp = true;
            }            
        }
        // ソート不要だったらフラグを下げる
        if (sort_tmp) {
            rep(i,N) cout << a[i] << " " ;
            cout << endl;
        }else{
            sort = false;
        }
    }   

    return 0;
}