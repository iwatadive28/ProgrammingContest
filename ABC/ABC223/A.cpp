#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int X;

int main(){
    cin >> X;
    if (X>=100 && X%100==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}