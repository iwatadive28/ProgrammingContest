#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main(){
    int n;
    cin >> n;
    set<string> name;
    bool same = false;
    rep(i,n){
        string s,t;
        cin >> s >> t;
        if(!name.count(s+" "+t)){
           name.insert(s+" "+t); 
        }
        else{
            same = true;
            break;
        }

    }
    cout << (same?"Yes":"No") << endl;
}