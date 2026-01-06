#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int qtd_janelas, cont = 0; cin >> qtd_janelas;

    if((qtd_janelas%2) == 0){
        for(int i = 1; i <= qtd_janelas+1; i = i+2){
            cont++;
        }
        cout << cont << '\n';
        for(int i = 1; i < qtd_janelas; i = i+2){
            cout << i << " ";
        }
        cout << qtd_janelas << '\n';
    }else if((qtd_janelas%2) != 0){
        for(int i = 0; i <= qtd_janelas; i = i+2){
            cont++;
        }
        cout << cont << '\n';
        for(int i = 1; i <= qtd_janelas+1; i = i+2){
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}