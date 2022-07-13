#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    string S[2];

    rep(i,2){
        cin >> S[i];
    }

    string ans = "Yes";
    if ((S[0][0]  != S[1][0]) | (S[0][1]  != S[1][1])){
        ans = "No";
    }

    if ((S[0][0]  == S[0][1]) & (S[0][0]  == '#')){
        ans = "Yes";
    }
    if ((S[1][0]  == S[1][1]) & (S[1][0]  == '#')){
        ans = "Yes";
    }

    cout << ans << endl;
}