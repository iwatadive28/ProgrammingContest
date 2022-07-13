#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int res = -1;
    for (int i = A; i <= B; i++){
        if (i%C == 0){
            res = i;
            break;
        }
    } 
    cout << res  << endl;    
}