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
    string X;
    cin >> X;
    
    bool weak = false;
    if (X[0] == X[1] & X[0] == X[2] & X[0] == X[3]) weak = true;
    rep(i,3){
        int x0 = (int(X[i]-'0')+1)%10;
        int x1 = (int(X[i+1]-'0'))%10;
        // cout << x0 << x1 << endl;

        if (x0!=x1) break;
        if (i==2) weak = true;
    }
    cout <<(weak?"Weak":"Strong") << endl;
}