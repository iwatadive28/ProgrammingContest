#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> bool chmax(T& a, T b){if (a<b){a=b;return true;}else{return false;}}
template<class T> bool chmin(T& a, T b){if (a>b){a=b;return true;}else{return false;}}
const ll INF = 1LL << 60;  //無限大
const ll MOD = 1000000007; //10^9 + 7
/*
*/

int nex[100009][26];

int main(){
    int N,K;
    string S;
    cin >> N >> K >> S;
    
    // 前計算
	for (int i = 0; i < 26; i++) nex[S.size()][i] = S.size();
	for (int i = (int)S.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if ((int)(S[i] - 'a') == j) {
				nex[i][j] = i;
			}
			else {
				nex[i][j] = nex[i + 1][j];
			}
		}
	}
    // 貪欲法
    // 一文字ずつ貪欲に決めていく
    string ans = "";
	int CurrentPos = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < 26; j++) {
			int NexPos = nex[CurrentPos][j];
			int MaxPossibleLength = (int)(S.size() - NexPos - 1) + i;
			if (MaxPossibleLength >= K) {
				ans += (char)('a' + j);
				CurrentPos = NexPos + 1;
				break;
			}
		}
	}
    cout << ans << endl;
}   