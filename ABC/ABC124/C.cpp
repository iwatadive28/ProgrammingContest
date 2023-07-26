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
    string S;
    cin >> S;

    // even:0,odd:1の場合
    int ans1 = 0;
    int ans2 = 0;
    rep(i,S.size()){
        if(i%2==0){
            if(S[i]=='0') ans1++;
            else          ans2++;
        }
        else{
            if(S[i]=='1') ans1++;
            else          ans2++;
        }
    }
    int ans = min(ans1,ans2);
    cout << ans << endl;
}