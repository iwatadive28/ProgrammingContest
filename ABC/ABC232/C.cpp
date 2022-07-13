#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//
using Graph = vector<vector<int>>;

int main(){
    int N,M;
    cin >> N >> M;
    
    vector<vector<bool>> X(N,vector<bool>(N)); 
    vector<vector<bool>> Y(N,vector<bool>(N));
    rep(i,M){
        int a,b;
        cin >> a >> b;
        --a;--b;
        X[a][b] = X[b][a] = true;
    }
    rep(i,M){
        int c,d;
        cin >> c >> d;
        --c;--d;
        Y[c][d] = Y[d][c] = true;
    }
    
    vector<int> p(N);
    iota(begin(p),end(p),0); // rep(i,N) p[i] = i;

    bool ans = false;
    do{
        bool tmp = true;
        rep(i,N) {
            // cout << p[i] << " ";
            for(int j=i+1;j<N;++j){
                if (X[i][j] != Y[p[i]][p[j]]){
                    tmp = false;
                    break;
                } 
            }
        }
        // cout << endl;
        if (tmp) {
            ans = true;
            break;
        }
    }while(next_permutation(p.begin(),p.end()));

    cout <<(ans?"Yes":"No") << endl;
}