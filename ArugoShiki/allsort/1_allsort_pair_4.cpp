#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int N;

int main() {
    
    cin >> N ;
    vector<string> S(110);
    rep(i,N) cin >> S[i];
    
    string ans = "No";
    for (int i=0;i<N-1;++i){
        for (int j=i+1;j<N;++j){
            if (S[i]==S[j]){
                ans = "Yes";
                break;
            }            
        }
        if (ans == "Yes") break;
    }	
    cout << ans << endl;
    return 0;
}