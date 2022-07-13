#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main(){
    string S,T;
    cin >> S >> T;
    
    if (S==T){
        cout << "Yes" << endl;
        return 0;
    }
    
    ll cnt_df = 0;
    vector<int>  n;
    ll N = S.size();
    for(ll i=0; i<N; ++i){
        if (S[i] != T[i]) {
            ++cnt_df;
            n.push_back(i);
        }
    }
    if (cnt_df != 2){
        cout << "No"  << endl;
        return 0;
    }
    if (abs(n[0] - n[1]) != 1){
        cout << "No"  << endl;
        return 0;
    }
    
    bool can = false;
    string Stmp = S;
    Stmp[n[0]] = S[n[1]];// 入れ替え
    Stmp[n[1]] = S[n[0]];// 入れ替え
    if (Stmp == T){
        can = true;
    }
    if (can) cout << "Yes" << endl;
    else     cout << "No"  << endl;

}