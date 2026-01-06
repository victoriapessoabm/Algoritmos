#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd; cin >> qtd;

    int magicalSources[qtd];
    long long int sum = 0, precisa = 0, total = 0;

    for(int i = 0; i < qtd; i++){
        cin >> magicalSources[i];
        sum = sum + magicalSources[i];

        if(sum < 0){
            precisa = abs(sum);
            sum = sum + precisa; 

            total = total + precisa;
        }
    }

    cout << total << '\n';

    return 0;
}