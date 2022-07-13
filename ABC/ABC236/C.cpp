#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    ll N,M;
    cin >> N >> M;
    string S[N];

    map<string,bool> mp;
    rep(i,N) {
        string s;
        cin >> s;
        mp[s] = false;
        S[i] = s;
    }

    rep(i,M){
        string t;
        cin >> t;
        mp[t] = true;
    }

    //
    rep(i,N){
        cout << (mp[S[i]] ? "Yes":"No" )<< endl;
    }
    
}