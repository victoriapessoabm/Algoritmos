#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int qtd;
    cin >> qtd;

    vector<int> numbers(qtd);
    for(int i = 0; i < qtd; i++){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int largest = numbers[qtd-1];

    int j = qtd-1;
    while(numbers[j] == largest){
        j--;
    }

    cout << numbers[j] << "\n";

    return 0;
}