#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_shoes;
    long long int bells;
    cin >> qtd_shoes >> bells;

    vector<long long int> R_shoes(qtd_shoes);
    vector<long long int> L_shoes(qtd_shoes);

    for(int i = 0; i < qtd_shoes; i++){
        cin >> R_shoes[i];
    }
    sort(R_shoes.begin(), R_shoes.end());

    for(int j = 0; j < qtd_shoes; j++){
        cin >> L_shoes[j];
    }
    sort(L_shoes.begin(), L_shoes.end());

    long long int cost; 
    int res = 0;
    for(int m = 0; m < qtd_shoes; m++){
        cost = R_shoes[m] + L_shoes[m];

        if(cost <= bells){
            res++;

            bells = bells - cost;
        }
    }

    cout << res << '\n';

     return 0;
}