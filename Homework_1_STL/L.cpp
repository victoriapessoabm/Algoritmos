#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int qtd_elements, size_window;
    cin >> qtd_elements >> size_window;
    long long int info[4];
    for(int i = 0; i < 4; i++){
        cin >> info[i];
    }

    long long int x, qtd_windows, result;

    //qtd de intervalos/windows
    x = qtd_elements%size_window;
    if(x == 0){
        qtd_windows = qtd_elements/size_window;
    }else if(x != 0){
        qtd_windows = x + 1;
    }
    long long int sums[qtd_windows], count = info[0], indice = 0, ind = 0;

    long long int numbers_generated[qtd_elements];
    numbers_generated[0] = info[0];
    for(int i = 1; i < qtd_elements; i++){
        numbers_generated[i] = (numbers_generated[i-1] * info[1] + info[2]) % info[3];

        if((i%size_window) != 0){
            count = count + numbers_generated[ind++];
        }else{
            sums[indice++] = count;
            count = 0;
            ind = indice;
        }
    }

    long long int res = sums[0];

    for(int i = 1; i < qtd_windows; i++){
        res = res ^ sums[i];
    }

    cout << res << '\n';

    return 0;
}

//NAO CONCLUI AINDA
