#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int countDigits(ll n){
    string tmp;
    tmp = to_string(n);
    return tmp.size();
}

ll A,B;


int main(){
    cin >> A >> B;
    
    string ans = "Easy";    
    // 1の位から比較
    int i=0;
    while(1){
        int a_tmp = A % 10;
        int b_tmp = B % 10;
        //printf("(i,a_tmp,b_tmp) = (%d,%d,%d)\n",i,a_tmp,b_tmp);
        if ((a_tmp + b_tmp) > 9){
            ans = "Hard";
            break;
        }
        A/=10;
        B/=10;
        i++;
        if (A==0|B==0)break;
    }

    cout << ans << endl;
}