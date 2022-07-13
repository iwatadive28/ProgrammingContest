#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

bool is_kaibun(int x){
    bool is_kaibun = true;
    string S = to_string(x);

    for(int i=0;i<S.length()/2;i++){
        if (S[i] != S[S.length()-i-1]){
            is_kaibun = false;
        }
    }
    return is_kaibun;
}

int L,R;

int main() {
	cin >> L >> R;
    
    int cnt = 0;
    for(int i=L;i<=R;++i){
        if (is_kaibun(i)){
            cnt++;
        }
    }    
    cout << cnt << endl;
    return 0;
}