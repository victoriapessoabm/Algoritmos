#include <bits/stdc++.h> //deu certo
const int MAXN = 1e5 + 5;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_cartoes, qtd_portoes;
    cin >> qtd_cartoes >> qtd_portoes;
    
    vector<pair<int, int>> autorizacoes(qtd_portoes);
    int L, R;
    for(int i = 0; i < qtd_portoes; i++){
        cin >> L >> R;
        autorizacoes[i] = {L, R}; //autorizacoes.push_back({L,R});
    }

    vector<int> flags(MAXN+1, 0);
    vector<int> psum(MAXN+1, 0);
    for(auto[l,r]: autorizacoes){
        flags[l]++;
        flags[r+1]--;
    }

    int count = 0;
    for(int i = 1; i <= MAXN; i++){
        psum[i] = psum[i-1] + flags[i]; 

        if(psum[i] == qtd_portoes){
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}