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
ull gcd(ull a, ull b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ull lcm(ull a, ull b){
  return a*b / gcd(a, b);
}

int main(){
    ull A,B,C,D,ans;
    cin >> A >> B >> C >> D;
    ans = B-A+1;
    // cout << ans << endl; 
    ans -= B/C;
    // cout << ans << endl;
    ans += (A-1)/C;
    // cout << ans << endl;
    ans -= B/D;
    // cout << ans << endl;
    ans += (A-1)/D;
    // cout << ans << endl;
    ans += B/lcm(C,D);
    // cout << ans << endl;
    ans -= (A-1)/lcm(C,D);
    // cout << ans << endl;

     cout << ans << endl;   
}
