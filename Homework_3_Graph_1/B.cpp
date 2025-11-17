#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n; //qtd de vértices
    vector<vector<int>> adj; //lista de adjacência 

    Solution(int n) : n(n), adj(n + 1) {} //construtor 

    void addEdge(int a, int b) { //adicionando arestas no grafo não-direcionado 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int dfs(int u, int parent, int &diameter) {
        int best1 = 0, best2 = 0;  // maiores alturas dos filhos

        for (int v : adj[u]) {
            if (v == parent) continue;
            int h = dfs(v, u, diameter);  // altura do filho

            if (h > best1) {
                best2 = best1;
                best1 = h;
            } else if (h > best2) {
                best2 = h;
            }
        }

        // caminho máximo que passa por u = melhor filho + segundo melhor
        diameter = max(diameter, best1 + best2);

        // altura da subárvore em u
        return best1 + 1;
    }

    // só pra ter a função análoga à diameterOfBinaryTree
    int diameterOfTree() {
        int diameter = 0;
        dfs(1, 0, diameter);  // podemos enraizar em 1
        return diameter;
    }

    // --------- DFS DE DISTÂNCIA (para Tree Distances I) ---------
    void dfsDist(int u, int parent, vector<int> &dist) {
        for (int v : adj[u]) {
            if (v == parent) continue;
            dist[v] = dist[u] + 1;
            dfsDist(v, u, dist);
        }
    }

    // resolve B - Tree Distances I
    vector<int> treeDistances() {
        vector<int> dist(n + 1, -1), distA(n + 1, -1), distB(n + 1, -1);

        // 1) DFS a partir de 1 pra achar um extremo A
        dist[1] = 0;
        dfsDist(1, 0, dist);
        int A = 1;
        for (int i = 1; i <= n; i++)
            if (dist[i] > dist[A]) A = i;

        // 2) DFS a partir de A pra achar B e distâncias até A
        distA[A] = 0;
        dfsDist(A, 0, distA);
        int B = A;
        for (int i = 1; i <= n; i++)
            if (distA[i] > distA[B]) B = i;

        // 3) DFS a partir de B pra pegar distâncias até B
        distB[B] = 0;
        dfsDist(B, 0, distB);

        // resposta: para cada nó, max(dist(A), dist(B))
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++)
            ans[i] = max(distA[i], distB[i]);

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Solution sol(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        sol.addEdge(a, b);
    }

    vector<int> ans = sol.treeDistances();

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
