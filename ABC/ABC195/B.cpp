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
const string UST = "UNSATISFIABLE";

int main(){
    int A,B,W;
    cin >> A >> B >> W;
    W*=1000;
    int mn,mx;
    
    int md = W%B;
    int ca = 0;
    while(md!=0 && md < A){
        ca++;
        if(W-A*ca < 0){
            cout << UST << endl;
            return 0;
        }
        md=(W-A*ca)%B;
    }
    mn = ca + (W-A*ca)/B;
    if ((W-A*ca)%B!=0) mn++;

    mx = W/A;
    cout << mn << " " << mx << endl;
}
