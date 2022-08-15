#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/
//
int main(){
    int H1,W1; cin >> H1 >> W1;
    vector<vector<ll>> A(H1,vector<ll>(W1));
    rep(i,H1) rep(j,W1) cin >> A[i][j];

    int H2,W2; cin >> H2 >> W2;
    vector<vector<ll>> B(H2,vector<ll>(W2));
    rep(i,H2) rep(j,W2) cin >> B[i][j];

    vector<vector<int>> Crow(H2,vector<int> (W2,-1));
    vector<vector<int>> Ccol(H2,vector<int> (W2,-1));

    int pr_ia = 0;
    rep(i,H2){ // B[i][*]を含む行があるか？
        for(int ia=pr_ia;ia<H1;++ia){
            vector<ll> tmpA = A[ia];
            vector<ll> tmpB = B[i]; // B[i]をA[i]が含むか？
            vector<int> idx(W2,-1);
            bool incl = false;
            int j = 0;
            rep(ja,W1){
                if(tmpA[ja]==tmpB[j]){
                    idx[j] = ja;
                    j++;
                    
                }
                if(j==W2) {//B[i]をA[ia]が含む場合
                    incl = true;
                    break;               
                }
            }
            if(incl){
                vector<int> idxr(W2,ia);
                Crow[i] = idxr;
                Ccol[i] = idx;
                pr_ia = ia+1;
                break;                
            }
            if(ia==H1-1) pr_ia = ia+1;
        }                    
    }

    bool ans = true;
    // 行が一致するか？
    rep(j,W2){
        int idx = Ccol[0][j];
        rep(i,H2){
            if(Ccol[i][j]!=idx | Ccol[i][j]==-1){
                // cout << "不一致" << i << "," << j << endl;
                ans = false;
                break;
            }
        }
    }

    // 列が一致するか？
    rep(i,H2){
        int idx = Crow[i][0];
        rep(j,W2){
            if(Crow[i][j]!=idx | Crow[i][j]==-1){
                // cout << "不一致" << i << "," << j << endl;
                ans = false;
                break;
            }
        }
    }

    /*
    rep(i,H2){
        rep(j,W2){
            cout << "(" << Crow[i][j] << "," << Ccol[i][j]<< ") ";
        }
        cout << endl;
    }
    */
    cout << (ans?"Yes":"No") << endl;   
}
