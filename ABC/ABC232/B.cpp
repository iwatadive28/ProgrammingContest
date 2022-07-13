#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
string S = "abcdefghijklmnopqrstuvwxyz";

int main(){
    
    string S,T;
    cin >> S;
    cin >> T;

    bool ans = true;
    // 1文字目がどうやったら一致するか確認する
    int k;
    k = T[0] - S[0];
    if (k<0){
        k = k+26;
    }    
    // printf("k=%d\n",k);
    
    for (int i=1;i<S.size();i++){
        // printf("i=%d,S=%c,T=%c,T-S=%d\n",i,S[i],T[i],T[i]-S[i]);
        if (T[i]-S[i] != k){
            if (T[i]-S[i]+26 != k){
                ans = false;
                break;
            }            
        }
    }

    if (ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}