#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main() {
	int N;
	cin >> N;

    bool is_sosu = true;
    if (N==1){
        is_sosu = false;
    }else{
        for (int i=2;i<N-1;++i){
            if (N%i == 0){
                is_sosu = false;
                break;
            }
        }
    }
	

    if (is_sosu){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}