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
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    int b;
    rep(i,N){
        if (S[i]=='1'){
            b = i;
            break;
        }
    }
    string ans;
    if (b%2==0){
        ans = "Takahashi";
    }else{
        ans = "Aoki";
    }
    cout << ans << endl;
}