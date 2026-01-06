#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int candidates, qtd_votes, vote, winner = 0, indice, indice_winner;
    cin >> candidates >> qtd_votes;

    int countingVotes[candidates] = {0};
    for(int i = 0; i < qtd_votes; i++){
        cin >> vote;
        indice = vote-1;
        countingVotes[indice]++;

        if(countingVotes[indice] > winner){
            cout << vote << '\n';
            winner = countingVotes[indice];
            indice_winner = vote - 1;
        }else if(countingVotes[indice] == winner){
            if(indice < indice_winner){
                indice_winner = indice;
                cout << vote << '\n';
            }else{
                cout << indice_winner+1 << '\n';
            }
        }else{
            cout << indice_winner+1 << '\n';
        }
    }

    return 0;
}