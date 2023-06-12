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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    char p,q;
    cin >> p >> q;
    map<char,int> mp;
    mp['A'] = 0;
    mp['B'] = mp['A'] + 3;
    mp['C'] = mp['B'] + 1;
    mp['D'] = mp['C'] + 4;
    mp['E'] = mp['D'] + 1;
    mp['F'] = mp['E'] + 5;
    mp['G'] = mp['F'] + 9;

    cout << abs(mp[p]-mp[q]) << endl;    
}