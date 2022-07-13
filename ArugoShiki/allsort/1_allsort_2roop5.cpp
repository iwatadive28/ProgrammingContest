#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int N;
string S;

int main() {
    
    cin >> N;
    
    int cnt = 0;
    rep(i,N){
        cin >> S;
        bool kaibun = true;
        int Slen = S.length();
        for (int j=0;j<Slen/2;j++){
            // printf("S[%d]=%c,S[%d]=%c\n",j,S[j],Slen-1-j,S[Slen-1-j]);
            if(S[j] != S[Slen-1-j]){
                kaibun = false;
                break;
            }
        }
        if (kaibun){
            cnt++;
        }
    }
	
    cout << cnt << endl;
    return 0;
}