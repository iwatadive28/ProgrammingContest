#include <bits/stdc++.h>
using namespace std;

// 2つのCharを比較する関数
// C0>C1:1, C0==C1:0, C0<C1:-1
int compchar(char C0, char C1,string X){
    int i,j;
    for (i = 0;i<26;i++){ // 文字が辞書の何番目に来るか
        if (C0 == X[i]){
            break;
        }
    }
    for ( j = 0;j<26;j++){ // 文字が辞書の何番目に来るか
        if (C1 == X[j]){
            break;
        }
    }

    if (i>j){
        return 1;
    }
    else if (i==j){
        return 0;
    }
    else if (i<j){
        return -1;
    }
}

int main(){
    string X;
    int N;
    cin >> X ;
    cin >> N ;

    vector<string> S(N);
    for (int i = 0; i<N ; i++){
        cin >> S[i];
    }   
    vector<int> rank(N);
    for (int i =0;i<N;i++){
        rank[i] = i;
    }

    // ソート
    // 
    for (int i = 0; i<N-1 ; i++){
        string Si = S[i];

        for (int j = i+1; j<N ; j++){
            string Sj = S[j];

            // 2つの文字を比較

            int cmpS = 0;
            int L;
            if (Si.length() < Sj.length()){
                L = Si.length();
            }else{
                L = Sj.length();
            }

            // 一致し続ける限り文字比較
            for (int i_l = 0; i_l < L ; i_l++){
                char C0 = Si[i_l];
                char C1 = Sj[i_l];

                if (compchar(C0,C1,X)==1){
                    cmpS = 1;
                    break  ;  
                }else if  (compchar(C0,C1,X)==-1){
                    cmpS = -1;
                    break  ;
                }                
            }
            // Ｌ文字目までもし一致している場合
            if (cmpS == 0){
                if (Si.length() > Sj.length()){
                    cmpS = +1;
                }else{
                    cmpS = -1;
                }
            }
            
            // ++ ランク付け入れ替え
            if (cmpS == 1){ // 
                int tmp = rank[i];
                rank[i] = rank[j];
                rank[j] = tmp;
            }
            /*
            cout << "Debug: Si=";
            cout << Si;
            cout << ",Sj=";
            cout << Sj;
            cout << ",L=";
            cout << L ;
            cout << ",Si.length()=";
            cout << Si.length() ;
            cout << ",Sj.length()=";
            cout << Sj.length() ;
            cout << ",cmpS=";
            cout << cmpS << endl;
            */
        }
    }

    // 並べ替え
    vector<string> S_out(N);
    for (int i = 0; i<N;i++){
        S_out[rank[i]] = S[i];
    }

    // 出力
    for(int i = 0; i<N ; i++){
        // cout << rank[i] ; 
        cout << S_out[i] << endl;    
    }
    
        
   
}