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
// const ll INF = 1LL << 60;  //無限大
const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    int N;
    cin >> N;

    string ans;
    rep(i,N+1){
        int tmp = INF;
        for(int j=1;j<=9;j++){
            if(N%j!=0) continue;
            if(i%(N/j)==0) chmin(tmp,j);
        }
        if(tmp==INF) ans+='-';
        else ans+=to_string(tmp);
    }
    cout << ans << endl;
}