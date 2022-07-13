#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main() {
	string S,T;
	cin >> S >> T;
        
    string ans = "No";
    for (int i=0;i<S.size();++i){
        if (S.substr(i,T.length()) == T){
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}