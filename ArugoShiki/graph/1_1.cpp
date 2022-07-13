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
    ll N,A,B;
    cin >> N >> A >> B;
    vector<string> S(N);
    rep(i,N) cin >> S[i];

    cout << (S[A][B]=='o'?"Yes":"No") << endl;
        
    return 0;
}