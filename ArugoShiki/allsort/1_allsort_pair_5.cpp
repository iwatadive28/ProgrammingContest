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
    
    cin >> N >> S;

    int cnt = 0;    
    for (int i=0;i<N-1;++i){
        for (int j=i+1;j<N;++j){
            if (S[i]==S[j]){
                cnt++;    
            }            
        }
    }	
    cout << cnt << endl;
    return 0;
}