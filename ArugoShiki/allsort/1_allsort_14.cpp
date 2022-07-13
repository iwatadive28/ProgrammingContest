#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main() {
	int A,B;
	cin >> A >> B;

    int ans = 1;
    for (int i=min(A,B);i>1;--i){
        if (A%i == 0 & B%i == 0){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}