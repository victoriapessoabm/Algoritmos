#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int qtdLinhas, qtdColunas;
    cin >> qtdColunas >> qtdLinhas;

    char grid[qtdLinhas][qtdColunas];
    char letra;
    for(int i = 0; i < qtdLinhas; i++){
        for(int j = 0; j < qtdColunas; j++){
            cin >> letra;
            grid[i][j] = tolower(letra);
        }
    }

    int tempi, tempj, guardai, guardaj, count = 0;
    for(int i = 0; i < qtdLinhas; i++){
        for(int j = 0; j < qtdColunas; j++){
            if(grid[i][j] == 'u'){
                //cima
                tempi = i;
                tempj = j;
                tempi--;
                guardai = tempi;
                if(guardai >= 0 && grid[guardai][tempj] == 'v'){
                    tempi--;
                    guardai = tempi;
                    if(guardai >= 0 && grid[guardai][tempj] == 'a'){
                        count++;
                    }
                }
                //baixo 
                tempi = i;
                tempj = j;
                tempi++;
                guardai = tempi;
                if(guardai < qtdLinhas && grid[guardai][tempj] == 'v'){
                    tempi++;
                    guardai = tempi;
                    if(guardai < qtdLinhas && grid[guardai][tempj] == 'a'){
                        count++;
                    }
                }
                //direita
                tempi = i;
                tempj = j;
                tempj++;
                guardaj = tempj;
                if(guardaj < qtdColunas && grid[tempi][guardaj] == 'v'){
                    tempj++;
                    guardaj = tempj;
                    if(guardaj < qtdColunas && grid[tempi][guardaj] == 'a'){
                        count++;
                    }
                }
                //esquerda
                tempi = i;
                tempj = j;
                tempj--;
                guardaj = tempj;
                if(guardaj >= 0 && grid[tempi][guardaj] == 'v'){
                    tempj--;
                    guardaj = tempj;
                    if(guardaj >= 0 && grid[tempi][guardaj] == 'a'){
                        count++;
                    }
                }
                //diag,cima,dir - [i--][j++]
                tempi = i;
                tempj = j;
                tempi--;
                tempj++;
                guardai = tempi;
                guardaj = tempj;
                if(guardai >= 0 && guardaj < qtdColunas && grid[guardai][guardaj] == 'v'){
                    tempi--;
                    tempj++;
                    guardai = tempi;
                    guardaj = tempj;
                    if(guardai >= 0 && guardaj < qtdColunas && grid[guardai][guardaj] == 'a'){
                        count++;
                    }
                }
                //diag, cima, esq - [i--][j--]
                tempi = i;
                tempj = j;
                tempi--;
                tempj--;
                guardai = tempi;
                guardaj = tempj;
                if(guardai >= 0 && guardaj >= 0 && grid[guardai][guardaj] == 'v'){
                    tempi--;
                    tempj--;
                    guardai = tempi;
                    guardaj = tempj;
                    if(guardai >= 0 && guardaj >= 0 && grid[guardai][guardaj] == 'a'){
                        count++;
                    }
                }
                //diag, baixo, dir - [i++][j++]
                tempi = i;
                tempj = j;
                tempi++;
                tempj++;
                guardai = tempi;
                guardaj = tempj;
                if(guardai < qtdLinhas && guardaj < qtdColunas && grid[guardai][guardaj] == 'v'){
                    tempi++;
                    tempj++;
                    guardai = tempi;
                    guardaj = tempj;
                    if(guardai < qtdLinhas && guardaj < qtdColunas && grid[guardai][guardaj] == 'a'){
                        count++;
                    }
                }
                //diag, baixo, esq - [i++][j--]
                tempi = i;
                tempj = j;
                tempi++;
                tempj--;
                guardai = tempi;
                guardaj = tempj;
                if(guardai < qtdLinhas && guardaj >= 0 && grid[guardai][guardaj] == 'v'){
                    tempi++;
                    tempj--;
                    guardai = tempi;
                    guardaj = tempj;
                    if(guardai < qtdLinhas && guardaj >= 0 && grid[guardai][guardaj] == 'a'){
                        count++;
                    }
                }
            }
        }
    }

    cout << count << '\n';

    return 0;
}