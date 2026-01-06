#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int testCases; cin >> testCases;
    long long int a, b, dif, moves;

    for(int i = 0; i < testCases; i++){
        cin >> a >> b;

        if(a == b){
            dif = 0;
            moves = 0;
        }else if(a < b){ //soma
            dif = b - a;

            if((dif%2) == 0){
                moves = 2;
            }else{
                moves = 1;
            }
        }else if(a > b){//sub
            dif = a - b;

            if((dif%2) == 0){
                moves = 1;
            }else{
                moves = 2;
            }
        }

        cout << moves << '\n';
    }

    return 0;
}