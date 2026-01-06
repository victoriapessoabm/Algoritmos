#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a_b, b_c, a_c, menor = 400;
    vector<int> possiveis_valores(6);

    cin >> a_b;
    cin >> a_c;
    cin >> b_c;

    possiveis_valores[0] = a_b + b_c;
    possiveis_valores[1] = a_c + b_c;
    possiveis_valores[2] = a_b + a_c;
    possiveis_valores[3] = b_c + a_c;
    possiveis_valores[4] = a_c + a_b;
    possiveis_valores[5] = b_c + a_b;
    
    for(int i = 0; i < 6; i++){
        if(possiveis_valores[i] < menor){
            menor = possiveis_valores[i];
        }
    }

    cout << menor << '\n';
    
    return 0;
}
