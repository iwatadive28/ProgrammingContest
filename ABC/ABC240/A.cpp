#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int a,b;
    cin >> a >> b;
    bool ans = false;
    if (abs(a-b)==1){
        ans = true;
    }
    else if (abs(a-b)==9){
        ans = true;
    }
    else{
        ans = false;
    }
    cout << (ans?"Yes":"No") << endl;
}