#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main(){
    int A,B;
    cin >> A >> B;
    ll ans = pow(32,A-B);
    
    cout << ans << endl;
}