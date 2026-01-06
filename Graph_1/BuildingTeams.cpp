#include <bits/stdc++.h> 

using namespace std;

bool dfs_bipartite(int v, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &color){
    vis[v] = true;
    for(int u: adj[v]){
        if(!vis[u]){
            color[u] = !color[v];
            if(!dfs_bipartite(u, adj, vis, color)) return false;
        }else if(color[v] == color[u]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_pupilos, qtd_amizades; //qtd_pupilos = qtd_vértices; qtd_amizades = qtd_arestas;
    cin >> qtd_pupilos >> qtd_amizades;

    //criando o grafo
    int u,v;
    vector<vector<int>> adj(qtd_pupilos+1);
    for(int i = 0; i < qtd_amizades; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(qtd_pupilos+1, false);
    vector<bool> color(qtd_pupilos+1, 0);

    bool bipartite = true;

    for(int i = 1; i < qtd_pupilos+1; i++){ //podem haver componentes desconexos no grafo 
        if(!vis[i]){
            if (!dfs_bipartite(i, adj, vis, color)) {
                bipartite = false;
                break;
            }
        }
    }

    if(bipartite){
        for(int i = 1; i < qtd_pupilos+1; i++){
            if(color[i] == 0){
                cout << 1 << " ";
            }else if(color[i] == 1){
                cout << 2 << " ";
            }
        }
    }else{
        cout << "IMPOSSIBLE";
    }

    cout << '\n';
  
    return 0;
}