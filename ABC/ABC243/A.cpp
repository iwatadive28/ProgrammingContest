#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
#define mod 998244353;
/*
*/
//

int main(){
    int V,A,B,C;
    cin >> V >> A >> B >> C;
    
    while(1){
        V-=A;
        if (V<0){
            cout << "F" << endl;
            return 0;
        }
        V-=B;
        if (V<0){
            cout << "M" << endl;
            return 0;
        }
        V-=C;
        if (V<0){
            cout << "T" << endl;
            return 0;
        }
    }       
}