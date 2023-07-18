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
// const int INF = 1000000000;
const ll MOD = 1000000007; //10^9 + 7
const double pi = 3.14159265358979;
/*
*/

int main(){
    string S;
    int T;
    cin >> S >> T;
    int y=0,x=0,q=0;
    for(auto c:S){
        if      (c=='U') y++;
        else if (c=='D') y--;
        else if (c=='R') x++;
        else if (c=='L') x--;
        else             q++;
    }
    int ans = abs(y)+abs(x);

    if(T==1) ans += q;
    else{
        ans -= q;
        if(ans<0){
            if(ans%2==0) ans = 0;
            else ans = 1;
        }
    }
    cout << ans << endl;
}