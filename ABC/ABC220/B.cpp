#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

ll num10(ll A, ll K){
    ll num = 0;
    int cnt = 0;
    while(A>0){
        if (A%10>=K) {
            num = -1;
            break;
        }
        num += A%10 * ll(pow(K,cnt));
        A   = A/10;
        cnt++;
    }
    return num;
}

int main(){
    ll K,A,B;
    cin >> K >> A >> B;
    // printf("A=%d,num10=%d\n",A,num10(A,K));
    // printf("B=%d,num10=%d\n",B,num10(B,K));
    if (num10(A,K)<0 || num10(B,K)<0){
        return 0;
    }
    cout << num10(A,K) * num10(B,K) << endl;    
}