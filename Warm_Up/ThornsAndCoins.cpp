#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int test_cases; cin >> test_cases;

    int length_path, count;
    string path;

    for(int i = 0; i < test_cases; i++){
        cin >> length_path; //tamanho do caminho 
        cin >> path; //caminho 
        count = 0;
        for(int j = 0; j < length_path; j++){
            if(path[j] == '@') count++;
            if(path[j] == '*'){
                if(j != (length_path-1) && path[j+1] == '*'){
                    break;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}