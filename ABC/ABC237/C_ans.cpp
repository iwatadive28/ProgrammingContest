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
    ll M = s.size();
    if(M <= 1)  return true;    
    
    rep(i,M/2){
        if (s[i] != s[M-1-i]) return false;
    }
    return true;
}


int main(){
    string S;
    cin >> S;

    ll n,x,y;
    n = S.size();
    // 先頭から連続する'a'をカウント O(N)
    x = 0;
    rep(i,n){
        if (S[i]=='a') ++x;
        else break;
    }
    // 末尾から連続する'a'をカウント O(N)
    y = 0;
    rep(i,n){
        if (S[n-1-i]=='a') ++y;
        else break;
    }
    
    // 全部'a'の場合
    if (n==x) {
        cout << "Yes"<< endl;
        return 0; 
    }

    // x>yの場合
    if (x>y) {
        cout << "No"<< endl;
        return 0; 
    }

    // x<=yの場合,回文を判定する
    ll m = n-(y-x);
    cout << (kaibun(S.substr(0,m))?"Yes":"No") << endl;    

    return 0;
}