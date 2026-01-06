#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int qtd, indice, maior = 0, soma = 0;
    cin >> qtd;
    int numbers[qtd];

    for(int i = 0; i < qtd; i++){
        cin >> numbers[i];
        if(numbers[i] > maior){
            maior = numbers[i];
            indice = i;
        }
    }

    int divisao = maior/2;

    for(int i = 0; i < qtd; i++){
        if(indice == i){
            soma = soma + divisao;
        }
        else{
            soma = soma + numbers[i];
        }
    }

    cout << soma << '\n';

    return 0;
}