#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int qtd; cin >> qtd;
    vector<int> segments(qtd);

    for(int i = 0; i < qtd; i++){
        cin >> segments[i];
    }

    sort(segments.begin(), segments.end(), greater<int>());

    bool triangle = false;

    for(int i = 0; i < qtd-2; i++){
        if(segments[i] < segments[i+1] + segments[i+2]){
            triangle = true;
        }
    }

    if(triangle){
        cout << "YES" << '\n';
    }else{
        cout << "NO" << '\n';
    }

    return 0;
}