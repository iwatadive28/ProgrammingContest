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

string func_S(int n){
    string s;
    if (n==1){
        return "1";
    }
    return func_S(n-1) + " " + to_string(n) +" "+ func_S(n-1);
}

int main(){
    int N;
    cin >> N;
    
    string ans = func_S(N);

    cout << ans << endl;
}