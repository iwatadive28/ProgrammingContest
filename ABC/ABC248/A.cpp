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
    vector<bool> flg(10,false);
    rep(i,S.size())  flg[S[i]-'0']= true;
    
    rep(i,10){
        if(!flg[i]) cout << i << endl;
    }
    
}