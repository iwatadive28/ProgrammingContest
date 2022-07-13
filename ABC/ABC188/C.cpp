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
    int N;
    cin >> N;
    vector<pair<int,int>> A1,A2;
    rep(i,pow(2,N)){
        int a;
        cin >> a;
        if (i<pow(2,N)/2) A1.push_back(make_pair(-a,i+1));
        else              A2.push_back(make_pair(-a,i+1));
    }
    sort(A1.begin(),A1.end());
    sort(A2.begin(),A2.end());
    
    int ans;
    if(A1[0].first < A2[0].first) ans = A2[0].second;
    else                          ans = A1[0].second;
    cout << ans << endl;
}
