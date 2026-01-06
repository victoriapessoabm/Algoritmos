#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    string path;
    cin >> path;
    int count = 0;

    for(int i = 1; i < path.size(); i++){
        if(path[i] == '-'){
            count++;
        }else{
           cout << count << " "; 
           count = 0;
        }
    }

    cout << '\n';

    return 0;
}