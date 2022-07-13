#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main(){
    double x;
    cin >> x;
    int ans = (x*10)/10;
    cout << ans;

    if (int(x*10)%10<=2) cout << "-";
    else if(int(x*10)%10>=7) cout << "+";
    cout << endl;
 
}