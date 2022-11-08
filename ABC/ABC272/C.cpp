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
const ll MOD = 1000000007; //10^9 + 7
/*
*/
int main(){
    ll N;
    cin >> N;
    vector<ll> Aodd;
    vector<ll> Aeven;
    rep(i,N){
        int a;
        cin >> a;
        if(a%2==0) Aeven.push_back(-a);
        else       Aodd.push_back(-a);
    }

    ll ans = -1;
    sort(Aodd.begin() ,Aodd.end());
    sort(Aeven.begin(),Aeven.end());

    if(Aodd.size() >=2) chmax(ans,-Aodd[0] -Aodd[1]);
    if(Aeven.size()>=2) chmax(ans,-Aeven[0]-Aeven[1]);

    cout << ans << endl;
}
