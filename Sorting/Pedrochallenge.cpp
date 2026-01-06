#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &array, int target){
    int low = 0;
    int high = array.size() - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(array[mid] == target){
            return array[mid];
        }else if(array[mid] < target){
            low = mid + 1;
        }else if(array[mid] > target){
            high = mid - 1;
        }
    }

    // if not found the target, return the closest number
    int a = abs(target - array[high]);
    int b = abs(target - array[low]);
    int result;
    if(a < b){
        result = array[high];
    }else if(b < a){
        result = array[low];
    }else if(a == b){
        result = min(array[high], array[low]);
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd_numbers;
    cin >> qtd_numbers;

    vector<int> numbers(qtd_numbers);
    for(int i = 0; i < qtd_numbers; i++){
        cin >> numbers[i]; 
    }
    sort(numbers.begin(), numbers.end());

    int qtd_queries;
    cin >> qtd_queries;

    int queries;
    for(int i = 0; i < qtd_queries; i++){
        cin >> queries;

        int result = binary_search(numbers, queries);
        cout << result << '\n';
    }

    return 0;
}