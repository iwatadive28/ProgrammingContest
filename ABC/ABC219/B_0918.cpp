#include <bits/stdc++.h>
using namespace std;

int main(){
    string S1,S2,S3,T;
    
    cin >> S1;
    cin >> S2;
    cin >> S3;
    cin >> T;

    for (int i=0;i<T.length();i++){
        if (T[i] == '1'){
            cout << S1;
        }
        else if (T[i] == '2'){
            cout << S2;
        }
        else if (T[i] == '3'){
            cout << S3;
        }
    }   
}