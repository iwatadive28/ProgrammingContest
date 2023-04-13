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
    ll A,B;
    cin >> A >> B;
    ll ans = 0;
    while(A!=B){
        ll d = abs(A-B);
        if(A>B){
            if(d%B==0){
                ans += d/B;
                A = B;
            }else{
                ans += (d/B+1);
                A = d%B;
            }
        }else{
            if(d%A==0){
                ans += d/A;
                B = A;
            }else{
                ans += (d/A+1);
                B = d%A;
            }
        }
    }
    cout << ans << endl;
}