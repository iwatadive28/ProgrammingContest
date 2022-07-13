#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
string S;

int main(){
    cin >> S;
    int n = S.size();
    
    vector<string> S1(n); // string, no
   
    rep(i,n){
        string S_tmp;
        S = S.substr(1,n) + S.substr(0,1);
        S1[i] = S;
    }
    
    sort(S1.begin(), S1.end());    
    
    cout << S1[0]   << endl;
    cout << S1[n-1] << endl;
    
}