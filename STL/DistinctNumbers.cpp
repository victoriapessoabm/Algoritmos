#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int qtd;
    cin >> qtd;

    vector<int> values(qtd);
    for(int i = 0; i < qtd; i++){
        cin >> values[i];
    }

    sort(values.begin(), values.end());

    int distinct_values = 1;
    for(int i = 0; i < qtd-1; i++){
        if(values[i] != values[i+1]){
            distinct_values++;
        }
    }

    cout << distinct_values << '\n';

    return 0;
}