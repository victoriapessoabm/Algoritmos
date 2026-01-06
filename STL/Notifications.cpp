#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int qtd_not; cin >> qtd_not;
    long long int relogio = 0, momento, duracao, tempo_not, duracao_video;
    pair<long long int, long long int> par;
    queue<pair<long long int, long long int>> fila;

    for(int i = 0; i < qtd_not; i++){
        cin >> tempo_not >> duracao_video;
        par.first = tempo_not;
        par.second = duracao_video;
        fila.push(par);
    }

    pair<long long int, long long int> topo_fila;
    for(int i = 0; i < qtd_not; i++){
        if(fila.size()){
            par = fila.front();
            momento = par.first;
            duracao = par.second;
            if(relogio >= momento){
                relogio = relogio + duracao;
            }
            else{
                relogio = momento;
                relogio = relogio + duracao;
            }
            fila.pop();
        }
    }

    cout << relogio << '\n';

    return 0;
}