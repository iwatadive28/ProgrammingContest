#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
#define mod 998244353;
/*
*/
//

string S;

char ABC(char X,ll n){
    if (X<'A'|X>'C'){
        printf("%c=Input Error.Please Input A-C.\n",X);
    }
    ll numX = X-'A';
    return 'A' + (numX+n)%3;
}

char func_ABC(ll t, ll k){
    if (t==0)       return S[k];
    else if(k==0)   return ABC(S[0],t);
    else {
        if (k%2==0) return ABC(func_ABC(t-1,k/2),1);
        else        return ABC(func_ABC(t-1,k/2),2);
    }
    
}

int main(){
    ll Q;
    cin >> S >> Q;
    vector<ll> t(Q),k(Q);
    rep(i,Q) cin >> t[i] >> k[i];

    rep(i,Q) cout << func_ABC(t[i],k[i]-1) << endl;  
}