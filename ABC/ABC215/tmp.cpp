#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int kj(int x){
    if (x==1) return x;
    return x*kj(x-1);
}

int main(){
    
    int n;
    cin >> n;
    cout << kj(n) << endl;

}