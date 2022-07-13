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
    ll N;
    cin >> N;
    ll M = 1<<N;
    ll L = N*N;
    
    if (N<5){
        cout << (M>L?"Yes":"No") << endl;
    }else{
        cout << (N>4?"Yes":"No") << endl;    
    }

    
}