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
    vector<ll> a(N);
    vector<bool> vol(N+2,false);

    int sold = 0;
    rep(i,N) {
        cin >> a[i];
        if(a[i]>=N+2) sold++; // N+2巻以上の時
        else if(vol[a[i]]) sold++;
        else vol[a[i]] = true;
    }

    int L=1;
    int R=N+1;
    while(true){
        while(vol[L]) L++;
        while(R!=0 && !vol[R]) R--;
        if(sold>=2){
            sold-=2;
            vol[L]=true;
        }
        else{
            if(L>=R) break;
            vol[R] = false;
            sold++;
        }
    }

    cout << L-1 << endl;
}
