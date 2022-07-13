#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int L,R;

int main() {
    
    cin >> L >> R;

    int cnt = 0;
    for (int i=L;i<=R-1;++i){
        for (int j=i+1;j<=R;++j){
            if(i%10 == j%10){
                // printf("(i,j)=(%d,%d)\n",i,j);
                cnt++;
            }        
        }
    }        
	
    cout << cnt << endl;
    return 0;
}