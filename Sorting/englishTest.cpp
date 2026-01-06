#include <bits/stdc++.h>

using namespace std;

bool binary_search(vector<string> &dictionary, string target){
    int low = 0;
    int high = dictionary.size() - 1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(dictionary[mid] == target){
            return true;
        }else if(dictionary[mid] < target){
            low = mid + 1;
        }else if(dictionary[mid] > target){
            high = mid - 1;
        }
    }

    return false;
}

int main(){
    ios::sync_with _studio(false);
    cin.tie(nullptr);

    int qtd_words_dict;
    cin >> qtd_words_dict;

    vector<string> dictionary(qtd_words_dict);
    for(int i = 0; i < qtd_words_dict; i++){
        cin >> dictionary[i]; //already sorted
    }

    int tries;
    cin >> tries;

    int count = 0;
    string word;
    for(int i = 0; i < tries; i++){
        cin >> word;

        if(binary_search(dictionary, word)){
            count++;
        }
    }
    
    cout << count << '\n';

    return 0;
}