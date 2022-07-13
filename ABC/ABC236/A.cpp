#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    string S;
    int a,b;
    cin >> S >> a >> b;

    char tmp;
    // tmp = S[b-1];
    // S[b-1] = S[a-1];
    // S[a-1] = tmp;
    a--;b--;
    swap(S[a],S[b]);
    cout << S << endl;
}