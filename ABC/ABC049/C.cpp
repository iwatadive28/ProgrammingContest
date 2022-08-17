#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (int)(n); ++i)

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main(){
    string S;
    cin >> S ;

    // 端から見ていく
    reverse(S.begin(),S.end());
    rep(i,4) reverse(divide[i].begin(),divide[i].end());

    // 
    bool can = true;
    for (int i = 0; i < S.size();) {
        bool can2 = false; // 4つのどれかでdivedeできるか？
        rep(j,4){
            string d = divide[j];
            if (S.substr(i,d.size()) == d) {
                can2 = true;
                i += d.size(); // iを進める
            }
        }

        if (!can2){        // 4つともNGだった場合
            can = false;
            break;
        }
    }

    if (can) cout << "YES" << endl;
    else     cout << "NO"  << endl;
}