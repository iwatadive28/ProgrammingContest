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
    string S;
    cin >> S;
    cout << "0";
    rep(i,3){
        cout << S[i];
    }
    cout << endl;
}