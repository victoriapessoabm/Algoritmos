#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int testCases; cin >> testCases;
    int horas, minutos, novahora;
    char doisPontos;
    string formato;

    for(int i = 0; i < testCases; i++){
        cin >> horas >> doisPontos >> minutos;

        if(horas < 12){
            formato = "AM";
            if(horas == 00){
                horas = 12;
            }
        }else if (horas > 12){
            formato = "PM";
            horas = horas%12;
        }else if(horas == 12){
            formato = "PM";
        }

        cout << setfill('0') << setw(2) << horas << doisPontos << setfill('0') << setw(2) << minutos << ' ' << formato << '\n';
    }

    return 0;
}