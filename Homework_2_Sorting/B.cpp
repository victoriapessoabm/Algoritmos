#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int clientes; cin >> clientes;
    vector<pair<long long int, long long int>> registro(clientes); 
    for(int i = 0; i < clientes; i++){
        cin >> registro[i].first >> registro[i].second;
    }

    vector<int> flags(MAXN+1, 0);
    vector<int> psum(MAXN+1, 0);
    for(auto [l,r]: registro){
        flags[l]++;
        flags[r+1]--;
    }

    int max = 0;
    for(int i = 1; i <= MAXN; i++){
        psum[i] = psum[i-1] + flags[i];

        if(psum[i] > max){
            max = psum[i];
        }
    }

    cout << max << '\n';

    return 0;
}