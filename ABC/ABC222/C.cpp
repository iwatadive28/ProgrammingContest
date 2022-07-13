#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

/*
*/
//

vector<int> janken(char X,char Y){
    vector<int> score = {0,0};

    if (X == Y){
        score[0] = 0;
        score[1] = 0;
    }
    else if (X == 'G' && Y == 'C'){
        score[0] = 1;
        score[1] = 0;
    }
    else if (X == 'C' && Y == 'P'){
        score[0] = 1;
        score[1] = 0;
    }
    else if (X == 'P' && Y == 'G'){
        score[0] = 1;
        score[1] = 0;
    }
    else if (X == 'C' && Y == 'G'){
        score[0] = 0;
        score[1] = 1;
    }
    else if (X == 'P' && Y == 'C'){
        score[0] = 0;
        score[1] = 1;
    }
    else if (X == 'G' && Y == 'P'){
        score[0] = 0;
        score[1] = 1;
    }

    return score;
}

int main(){
    
    int N,M;
    cin >> N >> M;
    
    pair<pair<int, int>, string> pairs[2*N]; // score,No,GCP     
    
    rep(i, 2*N){
        string S;
        cin >> S;
        pairs[i] = make_pair(make_pair(0,i),S);  
    }   
    
    rep(i,M){
        sort(pairs,pairs + 2*N); // 最初にソート

        for(int j=0;j<2*N;j+=2){
            char p1 = pairs[j].second[i];
            char p2 = pairs[j+1].second[i];
            vector<int> score_tmp = janken(p1,p2);
            pairs[j].first.first   += -1 * score_tmp[0];
            pairs[j+1].first.first += -1 * score_tmp[1];            
        } 
    }
   
    sort(pairs,pairs + 2*N);
    rep(i,2*N){
        // cout << pairs[i].first.first << pairs[i].first.second << pairs[i].second << endl; 
        cout << pairs[i].first.second+1 << endl;
    }   
    
}