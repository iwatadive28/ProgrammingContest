#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
const ll MOD = 998244353;
/*
*/
//
string dec2bin(ull n)
{
    string r;
    while (n != 0){
        r = ( n % 2 == 0 ? "0" : "1" )+r;
        n /= 2;
    }
    return r;
}

ull bin2dec(string x)
{
    ull r=0;
    ull n=x.size();
    rep(i,n){
        if(x[n-i-1]=='1') r += pow(2,i);
    }
    return r;
}

int main(){
    ull n,x;
    string s;
    cin >> n >> x;
    cin >> s;
    
    // L,R直後のUを削除する
    string T="";
    for(auto c:s){
        if (T.size()==0)       T.push_back(c);        
        else if (c=='U'){
            if (T.back()=='U') T.push_back(c); 
            else               T.pop_back();
        }
        else T.push_back(c); 
    }
    // rep(i,T.size()) cout << T[i] ;
    // cout << endl;
    
    
    string xbin = dec2bin(x);
    // cout << xbin << endl;
    for(char c:T){
        if (c=='U'& x!=1) xbin.pop_back();
        else if(c=='L')   xbin.push_back('0');
        else              xbin.push_back('1');
        // cout << xbin << endl;
    }
    ull ans = bin2dec(xbin);
    cout << ans << endl;
    /*
    for (char c : T) {
        if (c == 'U' & x!=1) x /= 2;
        else if (c == 'L') x = 2*x;
        else x = 2*x + 1;
    }
    
    cout << x << endl;
    */
}