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
bool kaibun(string s){
    // Base
    // cout << s << endl;
    if(s.size() <= 1)  return true;

    ll M = s.size();
    if (s[0]==s[M-1]){
        return kaibun(s.substr(1,M-2));
    }
    return false;
        
}

bool kasaka(string s){
    
    ll M = s.length();
    // cout << s << ",M = "<<  M << endl;
    
    // base
    if(M <= 1)  return true;
    
    // 両端がaの場合
    if (s[0]==s[M-1] & s[0] == 'a' ){
        return kasaka(s.substr(1,M-2));
    }    
    // 右がaの場合
    else if (s[M-1] == 'a'){
        return kasaka(s.substr(0,M-1));
    }     
    // 両端が同じ場合 
    else if (s[0]==s[M-1]){
        return kaibun(s.substr(1,M-2));
    }    
    return false;    
}

int main(){
    string S;
    cin >> S;

    //int M = S.size();
    //cout << S.substr(0,M-1) << endl;

    cout << (kasaka(S)?"Yes":"No") << endl;    
}