#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
ll mypow(ll x,ll y){
    ll res = 1;
    rep(i,y) res*=x;
    return res;
}

ll AZ2dec(string s){
    ll res = 0;
    
    rep(i,s.length()){
        int j = s.length()-i-1;
        int tmp = (int)(s[j]-'A')+1;
        res+= mypow(26,i)*tmp;
    }
    return res;
}

int main(){
    string S;
    cin >> S;
    cout << AZ2dec(S) << endl;
}
