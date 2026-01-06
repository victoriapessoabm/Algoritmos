#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long int menor = 1000000000;
    long long int qtd_arvores, qtd_luzes, tam_arvore;
    priority_queue<long long int> priority_arvores;
    cin >> qtd_arvores;
    cin >> qtd_luzes;
    int ordenado[qtd_arvores];

    for(int i = 0; i < qtd_arvores; i++){
        cin >> tam_arvore;
        priority_arvores.push(tam_arvore); 
    }

    for(int i = 0; i < qtd_arvores; i++){
        ordenado[i] = priority_arvores.top();
        priority_arvores.pop();
    }

    for(int i = 0; i <= qtd_arvores - qtd_luzes; i++){
        int res = ordenado[i] - ordenado[i+qtd_luzes-1];
        if(res < menor){
            menor = res;
        }
    }

    cout << menor << '\n';
    return 0;
}