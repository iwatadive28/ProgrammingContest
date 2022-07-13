#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
const ll INF = 1<<29;
/*
*/
//

int main(){
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (abs(x1-x2)>4 | abs(y1-y2)>4){
        cout << "No" << endl;     
        return 0;
    }

    bool ans = false;
    // 
    vector<pair<ll,ll>> pos(8);
    set<pair<ll,ll>> st;
    // x1,y1に対する距離sqrt(5)の点を持つ
    // pair<ll,ll> pr;
    st.insert(make_pair(x1+1,y1+2));
    st.insert(make_pair(x1+1,y1-2));
    st.insert(make_pair(x1-1,y1+2));
    st.insert(make_pair(x1-1,y1-2));
    st.insert(make_pair(x1+2,y1+1));
    st.insert(make_pair(x1+2,y1-1));
    st.insert(make_pair(x1-2,y1+1));
    st.insert(make_pair(x1-2,y1-1));
    
    // x2,y2に対する距離sqrt(5)の点が存在するか確認する
    if(st.count(make_pair(x2+1,y2+2))) ans = true;
    if(st.count(make_pair(x2+1,y2-2))) ans = true;
    if(st.count(make_pair(x2-1,y2+2))) ans = true;
    if(st.count(make_pair(x2-1,y2-2))) ans = true;
    if(st.count(make_pair(x2+2,y2+1))) ans = true;
    if(st.count(make_pair(x2+2,y2-1))) ans = true;
    if(st.count(make_pair(x2-2,y2+1))) ans = true;
    if(st.count(make_pair(x2-2,y2-1))) ans = true;
    
    // cout << (st.count(pr)?"st Yes":"st No") << endl; 
    
    cout << (ans?"Yes":"No") << endl; 
    return 0;
}