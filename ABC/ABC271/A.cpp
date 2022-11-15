#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    int n;
    cin >> n;
    
    int a,b;
    a = n/16;
    b = n%16;

    if(a<=9) cout << a;
    else     cout << (char)('A'+a-10);
    if(b<=9) cout << b;
    else     cout << (char)('A'+b-10);
    cout << endl;
}
