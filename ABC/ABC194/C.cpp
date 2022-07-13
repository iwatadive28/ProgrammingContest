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
    ll N;
    cin >> N;
    vector<ll> cnt(401,0);
    rep(i,N){
        int a;
        cin >> a;
        cnt[a+200]++;
    }

    ull ans = 0;
    for(int i = -200;i<=199;i++){
        for(int j=i+1;j<=200;j++){
            ans += cnt[i+200] * cnt[j+200] * pow(i-j,2);
        }        
    }    
    cout << ans << endl;
}
