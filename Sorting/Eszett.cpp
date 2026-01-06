#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    string capitalWord; cin >> capitalWord;
    int tam = capitalWord.size();
    char letter, lower;
    string newWord, otherWord, anotherWord;
    int count = 1;
    
    for(int i = 0; i < tam; i++){
        letter = capitalWord[i];

        if(letter == 'S'){
            if(capitalWord[i+1] == 'S' && (i<tam)){
                i++;
                if(capitalWord[i+1] == 'S' && (i<tam)){ //ha tres possibilidades
                    i++;
                    otherWord = newWord;
                    anotherWord = newWord;
                    newWord.push_back('s');
                    newWord.push_back('s');
                    newWord.push_back('s');
                    otherWord.push_back('B');
                    otherWord.push_back('s');
                    anotherWord.push_back('s');
                    anotherWord.push_back('B');
                    count = 3;
                }else{ //ha duas possibilidades
                    otherWord = newWord;
                    newWord.push_back('s');
                    newWord.push_back('s');
                    otherWord.push_back('B');
                    count = 2;
                }
            }else{
                newWord.push_back(tolower(letter));
                if(count == 2){
                otherWord.push_back(tolower(letter));
                }
                if(count == 3){
                    otherWord.push_back(tolower(letter));
                    anotherWord.push_back(tolower(letter));
                }
            }
        }else{
            newWord.push_back(tolower(letter));
            if(count == 2){
                otherWord.push_back(tolower(letter));
            }
            if(count == 3){
                otherWord.push_back(tolower(letter));
                anotherWord.push_back(tolower(letter));
            }
        }
    }

    if(count == 1){
        cout << newWord << '\n';
    }else if(count == 2){
        cout << newWord << '\n';
        cout << otherWord << '\n';
    }else if(count == 3){
        cout << newWord << '\n';
        cout << otherWord << '\n';
        cout << anotherWord << '\n';
    }
    

    return 0;
}