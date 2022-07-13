#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main(){
    ll N;
    cin >> N;
    // cout << N << endl;
    string s = "";
    while(N>0){
        // 偶数->魔法B
        if(N%2==0) {
            s = "B"+s;
            N/=2;
        }
        // 奇数->魔法A
        else{
            s = "A"+s;
            N--;
        }
    }
    cout <<  s << endl;
}