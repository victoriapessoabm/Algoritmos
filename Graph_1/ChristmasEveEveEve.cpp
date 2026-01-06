#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 25){
        cout << "Christmas" << '\n';
    }
    else if(n == 24){
        cout << "Christmas Eve" << '\n';
    }
    else if(n == 23){
        cout << "Christmas Eve Eve" << '\n';
    }
    else if(n == 22){
        cout << "Christmas Eve Eve Eve" << '\n';
    }

    return 0;
}