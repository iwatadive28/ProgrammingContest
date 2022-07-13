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
ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll lcm(ll a, ll b){
  return a*b / gcd(a, b);
}

int main(){
    ll N,A,B;
    cin >> N >> A >> B;

    ll ans = N*(N+1)/2;
    ans -= (N/A)*(N/A+1)*A/2;
    ans -= (N/B)*(N/B+1)*B/2;
    ll lab = lcm(A,B);
    ans += (N/lab)*(N/lab+1)*lab/2;
    cout << ans << endl; 
    /*
    // SN
    ll Sn = N*(N+1)/2;

    // SA,SB;
    ll Sa = (N/A)*(N/A+1)*A/2;
    ll Sb = (N/B)*(N/B+1)*B/2;
    
    // 
    ll lab = lcm(A,B);
    ll Sab = (N/lab)*(N/lab+1)*lab/2;

    // cout << "Sn,Sa,Sb,Sab = "<< Sn <<","<< Sa <<","<< Sb << "," << Sab << endl;

    ll ans = Sn - Sa - Sb + Sab;
    */
}