#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main(){
    ll N;
    cin >> N;
    ll ans=0;
    while(N>1){
        ans++;
        N/=2;
    }
    cout << ans << endl;    
}