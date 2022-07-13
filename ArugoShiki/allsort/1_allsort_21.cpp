#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main() {
	string S;
	char c;
    cin >> S;
    cin >> c;
    
    string ans = "No";
    rep(i,S.size()){
        if (S[i] == c){
            ans = "Yes";
        }
    }
    cout << ans << endl;

    return 0;
}