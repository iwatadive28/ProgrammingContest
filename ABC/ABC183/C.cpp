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
void printVector(const vector<ll>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main(){
    ll N,K;
    cin >> N >> K;
    vector<vector<ll>> T(N,vector<ll>(N));
    rep(i,N) rep(j,N) cin >> T[i][j];

    vector<ll> nums;
    rep(i,N) nums.push_back(i);
    ll ans = 0;
    do {
        ll time = 0;
        rep(i,N) time += T[nums[i]][nums[(i+1)%N]];
        if(time==K) ans++;
        // printVector(nums);
    } while (next_permutation(nums.begin()+1, nums.end()));
    
    cout << ans << endl;
}
