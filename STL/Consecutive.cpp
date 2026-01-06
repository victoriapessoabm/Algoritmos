#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int qtd_letters, queries;
    string word;
    
    cin >> qtd_letters >> queries;
    cin >> word;

    int start, end, pointer, answer = 0;
    
    for(int i = 0; i < queries; i++){
        cin >> start >> end;

        pointer = start-1;
        while(pointer < end-1){
            if(word[pointer] == word[pointer+1]){
                answer++;
            }
            pointer++;
        }

        cout << answer << '\n';
        answer = 0;
    }


    

    return 0;
}