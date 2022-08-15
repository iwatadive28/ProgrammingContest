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
    int R,C;
    cin >> R >> C;
    R--;C--;
    
    vector<string> S(15);
    S[0] = "###############";
    S[1] = "#.............#";
    S[2] = "#.###########.#";
    S[3] = "#.#.........#.#";
    S[4] = "#.#.#######.#.#";
    S[5] = "#.#.#.....#.#.#";
    S[6] = "#.#.#.###.#.#.#";
    S[7] = "#.#.#.#.#.#.#.#";
    S[8] = "#.#.#.###.#.#.#";
    S[9] = "#.#.#.....#.#.#";
    S[10]= "#.#.#######.#.#";
    S[11]= "#.#.........#.#";
    S[12]= "#.###########.#";
    S[13]= "#.............#";
    S[14]= "###############";    

    cout << (S[R][C]=='.'?"white":"black") << endl;   
}
