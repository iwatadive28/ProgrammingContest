#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    int N;
    cin >> N;
    string S[N];
    rep(i,N){
        cin >> S[i];
    }

    int max = 0;
    string ans;

    rep(i,N){
        string kouho = S[i];
        int cnt = 0;
        rep(j,N){
            if (S[j] == kouho){
                cnt++;
            }
        }
        if (max < cnt){
            max = cnt;
            ans = kouho;
        }
    }
    cout << ans << endl;
}