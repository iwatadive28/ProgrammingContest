#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    int N,value;
   
    cin >> N >> value;
    int data[N];
    bool flag = false;
    
    rep(i,N){
        cin >> data[i];
        if (data[i] == value){
            flag = true;
        }
    }
    
    if (flag){
        cout << "Yes" << endl;    
    }else{
        cout << "No" << endl;    
    }

    
}