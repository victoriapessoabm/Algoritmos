#include <bits/stdc++.h> 

using namespace std;

vector<int> toposort(vector<pair<int, int>> &edges, vector<vector<int>> &adj, int deg[], int qtd_cursos){
    for(int i = 1; i <= qtd_cursos; i++){
        deg[i] = 0;
    }
    
    for(auto[u, v] : edges){
        deg[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= qtd_cursos; i++){
        if(deg[i] == 0) q.push(i);
    }

    vector<int> ordenados;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ordenados.push_back(u);
        for(int v: adj[u]){
            deg[v]--;
            if(deg[v] == 0) q.push(v);
        }
    }

    return ordenados;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //entrada inicial 
    int qtd_cursos, exigencias;
    cin >> qtd_cursos >> exigencias;

    //criando um grafo acíclico direcionado (DAG) 
    int u,v;
    vector<pair<int, int>> edges;
    vector<vector<int>> adj(qtd_cursos+1);
    for(int i = 0; i < exigencias; i++){
        cin >> u >> v;
        adj[u].push_back(v); //grafo em lista de adjacência
        edges.push_back({u,v}); //guarda as arestas 
    }

    //recebendo os cursos ordenados
    vector<int> cursosOrdenados;
    int deg[qtd_cursos+1];
    cursosOrdenados = toposort(edges, adj, deg, qtd_cursos);

    //printando os cursos na ordem correta
    if(qtd_cursos != cursosOrdenados.size()){
        cout << "IMPOSSIBLE" << '\n';
    }else{
        for(int i = 0; i < qtd_cursos; i++){
            cout << cursosOrdenados[i] << " ";
        }
        cout << '\n';
    }
  
    return 0;
}