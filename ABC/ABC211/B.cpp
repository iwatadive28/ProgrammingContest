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
    
    vector<bool> A(4,false); //H , 2B , 3B , HR
    rep(i,4) {
        string s;
        cin >> s;
        if     (s=="H")  A[0] = true;
        else if(s=="2B") A[1] = true;
        else if(s=="3B") A[2] = true;
        else if(s=="HR") A[3] = true;
    }
    
    string ans;
    if (A[0]&A[1]&A[2]&A[3]) ans = "Yes";
    else ans = "No";

    cout << ans << endl;
}