#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main(){
    string S;
    int K;
    cin >> S >> K;
    // 全列挙
    sort(S.begin(),S.end()); // 1) 辞書順にソートされていること
    while(K>1){
        next_permutation(S.begin(), S.end()); // 辞書順に全列挙
        K--;
    }
    cout << S << endl;
}

/*
int main(){
    string S;
    int K;
    cin >> S >> K;
    vector<int> n(S.length());
    iota(n.begin(),n.end(),0);
    
    vector<string> vec;
    
    // 全列挙
    int cnt =0;
    do {
        string tmp = S;
        rep(i,S.length()) tmp[n[i]] = S[i];
        vec.push_back(tmp);
    } while (next_permutation(n.begin(), n.end()));
    
    // Sort
    sort(vec.begin(),vec.end());
    
    // 重複を除く
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    cout << vec[K-1] << endl;
}
*/