#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

string S;
string T = "oxx";

int main(){
    cin >> S;
    bool ans = true;
    
    int st;
    if (S[0]=='o'){ // oxx
        st = 0;
    }else if(S[0] == 'x' & S[1]== 'x' ){ // xxo
        st = 1;
    }else{ // xox~
        st = 2;
    }

    for(int i=1;i<S.length();++i){
        int idx = (st+i)%3; 
        if (S[i] != T[idx]){
            ans = false;
        }
    }


    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}