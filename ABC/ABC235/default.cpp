#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

int main(){
    int N;
    cin >> N;
    pair<pair<string, int>,int> pairs[N];
    
    rep(i,N){
        string S;
        int P;
        cin >> S >> P;
        pairs[i] = make_pair(make_pair(S,-1*P),i); 
    }

    sort(pairs,pairs+N);
    rep(i,N){
        cout << pairs[i].second + 1 << endl;
    }
}