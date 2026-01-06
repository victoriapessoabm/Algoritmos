#include <bits/stdc++.h>

using namespace std;

int main(){
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int quantidade_vilas; cin >> quantidade_vilas;
     map<long long int, long long int> coordenadas;

     long long int coordenada_x;
     for(int i = 0; i < quantidade_vilas; i++){
        cin >> coordenada_x;
        coordenadas[coordenada_x] = i;
     }

     int moradores[quantidade_vilas];
     long long int moradorPorVila;
     for(int i = 0; i < quantidade_vilas; i++){
        cin >> moradorPorVila;
        moradores[i] = moradorPorVila;
     }

     long long int psum[quantidade_vilas+1] = {0};
     for(int i = 0; i < quantidade_vilas; i++){
        psum[i+1] = psum[i] + moradores[i];
     }

     int queries; cin >> queries;
     long long int L, R, result;

     for(int i = 0; i < queries; i++){
        cin >> L >> R;

        auto L_1 = coordenadas.lower_bound(L);
        if(L_1 == coordenadas.end()){
            cout << 0 << '\n';
            continue;
        }
        long long int L_psum = L_1->second;

        auto R_1 = coordenadas.upper_bound(R);
        if(R_1 == coordenadas.begin()){
            cout << 0 << '\n';
            continue;
        }
        R_1 = prev(R_1);
        long long int R_psum = R_1->second;
        
        if(L_psum > R_psum){
            cout << 0 << '\n';
            continue;
        }

        result = psum[R_psum+1] - psum[L_psum];

        cout << result << '\n';
     }

     return 0;
}