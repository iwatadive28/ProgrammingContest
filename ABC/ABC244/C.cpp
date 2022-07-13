#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    int N;
    cin >> N;
    
    vector<bool> ans(2*N+1,true);

    while(true){
        // 高橋くんが宣言
        int taka;
        rep(i,2*N+1){
            if(ans[i]){
                taka = i+1;
                break;
            }
        }
        cout << taka << endl << flush;
        ans[taka-1] = false;

        // 青木くんが宣言
        int aoki;
        cin >> aoki;
        if (aoki == 0){
            break;
        }
        ans[aoki-1] = false;
    }

    return 0;    
}