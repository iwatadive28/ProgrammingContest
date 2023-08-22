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
    int M;
    cin >> M;
    vector<int> D(M,0);
    int sum = 0;
    rep(i,M){
        cin >> D[i];
        sum += D[i];
    }
    int mid = sum/2+1;
    
    int a=0,b=0;
    rep(i,M){
        if(mid<=D[i]){
            a=i+1;
            b=mid;
            break;
        }
        mid-=D[i];
    }
    cout << a << " " << b << endl;
}