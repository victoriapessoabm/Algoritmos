#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string word;
    int count = 0;
    for(int i = 1; i < 13; i++){ //12 strings
        cin >> word;
        if(word.size() == i){
            count++;
        }
    }
    
    cout << count << '\n';

    return 0;
}