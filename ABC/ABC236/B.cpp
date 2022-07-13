#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    ll N;
    cin >> N;
    ll A[4*N-1];
    vector<int> cnt(N,0);
    
    rep(i,4*N-1){
        ll a;
        cin >> a;
        cnt[a-1]++;
    } 
    
    int ans;
    rep(i,N){
        if(cnt[i]!=4) ans = i+1;
    }
    cout << ans << endl;
}