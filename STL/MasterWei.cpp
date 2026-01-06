#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    long long int ano_mestre, ano_aprendiz, ano_sabio;
    cin >> ano_mestre >> ano_aprendiz;
    
    ano_sabio = (2*ano_aprendiz - ano_mestre);

    cout << ano_sabio << '\n';

    return 0;
}