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
    cin >> S;

    if (S.substr(S.size()-2,S.size()) == "er"){
        cout << "er" << endl;
    }
    else if (S.substr(S.size()-3,S.size()) == "ist"){
        cout << "ist" << endl;
    }
}