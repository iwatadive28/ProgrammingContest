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
    double x,y,z;
    cin >> x >> y >> z;
    int ans = -1;
    if(x/y<0 || y/x>1){
        ans = abs(x);
        // cout << "No wall" << endl;
    }else{
        if(0<z/y && z/y<1){
            ans = abs(x);
            // cout << "z in y" << endl;
        }
        else if(y/z<0){
            ans = 2*abs(z) + abs(x);
            // cout << "z side y" << endl;
        }
        else if(z/y<1){
            ans = -1;
            // cout << "z over y" << endl;
        }
    }
    
    cout << ans << endl;
}