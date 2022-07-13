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
//
bool isodd(ll x){
    return (x%2==1);
}

int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    char ans;

    if(isodd(C)){
        if(A<B)       ans = '<';
        else if(A==B) ans = '=';
        else          ans = '>';
    }
    else{
        if(abs(A)<abs(B))       ans = '<';
        else if(abs(A)==abs(B)) ans = '=';
        else                    ans = '>';
    }

    cout << ans << endl;
}