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

// string Stest = "0001111";
vector<ll> color;


int main(){
    ll N;
    cin >> N;

    int c=20;
    ll l = 0;
    ll r = N-1;
    while(c>0){
        char s;
        ll x=(r+l)/2;
        cout << "? " << x+1 << endl;
        cin >> s;
        // S[x]=Stest[x]; cout << Stest[x] << endl;

        if(s=='0') l=x;
        else       r=x;
        if(l+1==r){
            cout << "! "<< r << endl;
            break;
        }
        //*/               
        c--;
    }
}