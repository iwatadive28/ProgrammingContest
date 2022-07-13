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
    int n,a,y,x;
    cin >> n >> a >> x >> y;
    
    int ans = 0;
    int cnt = 0;
    while(cnt<n){
        cnt++;
        if (cnt>a){
            ans+=y;
        }else{
            ans+=x;
        }
    }

    cout << ans << endl;
}