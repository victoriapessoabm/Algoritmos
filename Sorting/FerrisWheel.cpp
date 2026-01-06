#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd;
    long long int max_weight;
    cin >> qtd >> max_weight;

    int l = 0, r = qtd-1, count = 0, total = 0;
    vector<long long int> children(qtd);

    for(int i = 0; i < qtd; i++){
        cin >> children[i];
    }
    sort(children.begin(), children.end());

    while(l <= r){
        if(children[r] < max_weight){
            total = children[l] + children[r];
            if(total <= max_weight){
                count++;
                l++;
                r--;
            }else{
                r--;
                count++;
            }
        }else{
            count++;
            r--;
        }
    }

    cout << count << '\n';    

    return 0;
}