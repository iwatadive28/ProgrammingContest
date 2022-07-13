#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main(){
    string S;
    int K;
    cin >> S >> K;
    
    vector<string> vec;
    // 全列挙
    sort(S.begin(),S.end());
    do {
        vec.push_back(S);
    } while (next_permutation(S.begin(), S.end()));
    
    cout << vec[K-1] << endl;
}
