#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

/*
*/
//

int main(){
    cout << "Start Game!" << endl;

    // Aさんの候補を表す区間[left,right)と表す
    int left = 20, right = 36;

    // Aさんの数を1つに絞れないうちは繰り返す
    while(right-left > 1){
        int mid = (right+left)/2; // 区間の真ん中

        // mid以上かを聞いて、回答をYes/Noで受け取る
        cout << "Is the age less than " << mid << " ?(yes/no)" << endl;

        string ans;
        cin >> ans;
        // 回答に応じて、ありうる数の範囲を絞る
        if (ans=="yes") right = mid;
        else            left  = mid;
    
    }

    // ズバリあてる
    cout << "The age is " << right << "!" << endl;
    cout << "left = " << left ;
    cout << ",right = " << right <<  endl;
    
    return 0;
}