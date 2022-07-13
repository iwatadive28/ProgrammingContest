#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    ll N,P;
    cin >> N >> P;
    
    ll cnt = 0;
    
    rep(i,N) {
        int a;
        cin >> a;
        if (a < P){
            ++cnt;
        }
    }
    
    cout << cnt << endl;
}