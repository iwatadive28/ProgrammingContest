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
    string T;
    rep(i,3) cin >> S[i];
    rep(i,3) cin >> T[i];
    

    int cnt = 0;
    rep(i,3) if (S[i]!=T[i]) ++cnt;
    
    if(cnt==2){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    
    return 0;    
}