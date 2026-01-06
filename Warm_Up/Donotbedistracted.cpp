#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int testCases; 
    cin >> testCases;

    int sizeWord, count = 0;
    string word, newWord;
    bool answer = true;
    
    for(int i = 0; i < testCases; i++){
        cin >> sizeWord;     
        cin >> word;

        for(int j = 0; j < sizeWord-1; j++){
            if(word[j] != word[j+1]){
                newWord.push_back(word[j]);
                if(j+1 == sizeWord-1){
                    newWord.push_back(word[j+1]);
                }
            }
            if(j+1 == sizeWord-1){
                if(word[j] == word[j+1]){
                    newWord.push_back(word[j]);
                }
            }
        }

        count = newWord.size();

        if(count != 0){
            sort(newWord.begin(), newWord.end());
        }
        
        for(int m = 0; m < count-1; m++){
            if(newWord[m] == newWord[m+1]){
                answer = false;
                break;
            }
        }

        if(answer){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }

        for(int n = 0; n < count; n++){
            newWord.pop_back();
        }
        answer = true;
        count = 0;
    }

    return 0;
}