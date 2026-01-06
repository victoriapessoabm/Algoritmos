#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    string S,T;
    cin >> S >> T;

    int tam_S = S.size();

    vector<char> precede;
    for(int i = 1; i < tam_S; i++){
        if(isupper(S[i])){
            precede.push_back(S[i-1]);
        }
    }
    
    int tam_precede = precede.size();
    int count = 0;
    for(int i = 0; i < tam_precede; i++){
        char pos = T.find(precede[i]);

        if(0 <= pos && pos < T.size()){
            if(precede[i] == T[pos]){
                count++;
            }
        }
    }

    if(count == tam_precede){
        cout << "Yes" << '\n';
    }else{
        cout << "No" << '\n';
    }
    
    return 0;
}