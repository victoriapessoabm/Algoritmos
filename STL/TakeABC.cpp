#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string word;
    cin >> word;
    string new_word;

    int tam = word.size();

    for(int i = 0; i < tam; i++){
        new_word.push_back(word[i]);
        if(new_word[new_word.size()-1] == 'C'){
            if(new_word[new_word.size()-2] == 'B'){
                if(new_word[new_word.size() - 3] == 'A'){
                    for(int j = 0; j < 3; j++){
                        new_word.pop_back();
                    }
                }
            }
        }
    }

    cout << new_word << '\n';

    return 0;
}