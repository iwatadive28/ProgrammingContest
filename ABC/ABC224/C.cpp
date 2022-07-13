#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
int N;
int X[310],Y[310];

int main(){
    cin >> N;

    rep(i,N){
        cin >> X[i] >> Y[i]; 
    }
    
    int cnt = 0;
    for (int i=0; i<N-2; ++i){
        for (int j=i+1; j<N-1; ++j){
            for (int k=j+1; k<N; ++k){
                double S = 0.5* abs((X[i]-X[k])*(Y[j]-Y[k])-(X[j]-X[k])*(Y[i]-Y[k]));
                //printf("(X[%d],X[%d],X[%d])= (%d,%d,%d) ,(Y[%d],Y[%d],Y[%d])= (%d,%d,%d), S = %f \n", i,j,k,X[i],X[j],X[k],i,j,k,Y[i],Y[j],Y[k],S);
                if (S>0){
                    cnt ++;
                }
            }
        }   
    }

    cout << cnt << endl;
}