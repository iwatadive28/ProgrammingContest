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
    // 乳固形分 A+B
    //  - 無脂乳固形分 A
    //  - 乳脂肪分     B
    ll A,B;
    cin >> A >> B;
    if (A+B>=15 && B>=8)      cout << 1 << endl;
    else if (A+B>=10 && B>=3) cout << 2 << endl;
    else if (A+B>=3)          cout << 3 << endl;
    else                      cout << 4 << endl;
    
}
