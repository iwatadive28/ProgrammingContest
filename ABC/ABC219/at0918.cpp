#include <bits/stdc++.h>
using namespace std;

int main(){
    int A[200];
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    int res = 0;

    while(true){
        bool exist_odd = false;
        for (int i=0;i<N;i++){
            if (A[i]%2 == 1){
                exist_odd = true;
            }
        }

        if (exist_odd == true){
            break;
        }

        for (int i=0;i<N;i++){
            A[i] = A[i]/2;
        }
        res++;
    }
    cout << res << endl;
}