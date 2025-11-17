#include <bits/stdc++.h> 

using namespace std;

int dfs_ciclo(int atual, int anterior, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ciclo){
    if(vis[atual]) return atual;
    vis[atual] = true;

    for(int nxt: adj[atual]){
        if(nxt == anterior) continue;
        int fim = dfs_ciclo(nxt, atual, adj, vis, ciclo);

        if(fim == -2) return -2;
        if(fim != -1){
            ciclo.push_back(atual);
            if(atual == fim) return -2;
            else return fim;
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_cidades, qtd_vias;
    cin >> qtd_cidades >> qtd_vias;

    //criando o grafo 
    int u, v;
    vector<vector<int>> adj(qtd_cidades+1);
    for(int i = 0; i < qtd_vias; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //descobrindo se há ciclo e qual eh
    vector<bool> vis(qtd_cidades+1, false);
    vector<int> ciclo;
    int r = -1;
    for(int i = 1; i <= qtd_cidades; i++){
        if(!vis[i]){
            r = dfs_ciclo(i, -1, adj, vis, ciclo);
            if(r != -1) break; //ciclo encontrado 
        }
    }
  
    if(r == -1){
        cout << "IMPOSSIBLE" << '\n';
    }else{
        cout << ciclo.size() + 1 << '\n';
        for(int m : ciclo){
            cout << m << " ";
        }
        cout << ciclo[0] << " ";
        cout << '\n';
    }

    return 0;
}