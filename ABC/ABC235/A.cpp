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
    
    int a = N/100;
    int b = (N/10)%10;
    int c = N%10;

    // printf("(%d,%d,%d)\n",a,b,c);

    int ans;
    ans = (a*100+b*10+c) + (b*100+c*10+a) + (c*100+a*10+b);    
    cout << ans << endl;
    
}