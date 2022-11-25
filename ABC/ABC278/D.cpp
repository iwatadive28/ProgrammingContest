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
    int n,q;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n) {
        int a;
        cin >> a;
        mp[i] = a;
    }
    ll y=0;  

    cin >> q;    
    vector<ll> ans;
    
    rep(i,q){
        int qr;
        cin >> qr;
        if(qr==1){
            cin >> y;
            mp.clear();
        }
        if(qr==2){
            int j,x;
            cin >> j >> x;
            j--;
            mp[j]+=x;
        }
        if(qr==3){
            int j;
            cin >> j;
            j--;
            ans.push_back(mp[j]+y);
        }
    }

    for(auto x:ans) cout << x << endl;
}
