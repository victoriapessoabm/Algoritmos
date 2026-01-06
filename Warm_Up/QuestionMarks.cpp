#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int testCases; cin >> testCases;
    int n, misses = 0, countA = 0, countB = 0, countC = 0, countD = 0;
    string word;

    for(int i = 0; i < testCases; i++){
        cin >> n >> word;

        sort(word.begin(), word.end());

        for(int j = 0; j < 4*n; j++){
            if(word[j] == '?'){
                misses++;
            }else if(word[j] == 'A'){
                countA++;
            }else if(word[j] == 'B'){
                countB++;
            }else if(word[j] == 'C'){
                countC++;
            }else if(word[j] == 'D'){
                countD++;
            }
        }

        if(countA > n){
            misses = misses + (countA - n);
        }
        if(countB > n){
            misses = misses + (countB - n);
        }
        if(countC > n){
            misses = misses + (countC - n);
        }
        if(countD > n){
            misses = misses + (countD - n);
        }

        int res;
        res = 4*n - misses;

        cout << res << '\n';

        misses = 0; countA = 0; countB = 0; countC = 0; countD = 0;
    }

    return 0;
}