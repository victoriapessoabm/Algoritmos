#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_shops; cin >> qtd_shops;

    vector<int> valores_bebida(qtd_shops);
    for(int i = 0; i < qtd_shops; i++){
        cin >> valores_bebida[i];
    }

    sort(valores_bebida.begin(), valores_bebida.end());

    int qtd_dias; cin >> qtd_dias; 
    
    long long int dinheiro;
    for(int i = 0; i < qtd_dias; i++){
        cin >> dinheiro;

        auto ub = upper_bound(valores_bebida.begin(), valores_bebida.end(), dinheiro);
        int pos_ub;
        if(ub == valores_bebida.end()){
            pos_ub = qtd_shops;
        }else{
            pos_ub = ub - valores_bebida.begin();
        }
        
        cout << pos_ub << '\n';

    }   

     return 0;
}