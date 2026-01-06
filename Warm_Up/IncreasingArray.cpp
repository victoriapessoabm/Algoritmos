#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int arraySize; cin >> arraySize;
    vector<long long int> vetor(arraySize);
    long long int sub, count = 0;

    for(int i = 0; i < arraySize; i++){
        cin >> vetor[i];

        if(i > 0){
            if(vetor[i] < vetor[i-1]){
                sub = vetor[i-1] - vetor[i];
                count = count + sub;
                vetor[i] = vetor[i] + sub;
            }
        }
    }

    cout << count << '\n';

    return 0;
}