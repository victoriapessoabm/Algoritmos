#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &array, vector<int> &tmp, int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end) {
        if(array[i] <= array[j]) tmp[k++] = array[i++];
        else tmp[k++] = array[j++];
    }
    while(i <= mid) tmp[k++] = array[i++];
    while(j <= end) tmp[k++] = array[j++];

    for(int t = start; t <= end; t++){
        array[t] = tmp[t];
    }
}

void mergesort(vector<int> &array, vector<int>& tmp, int start, int end){
    if(start < end) {
        int mid = (start + end) / 2;
        mergesort(array, tmp, start, mid);
        mergesort(array, tmp, mid + 1, end);
        merge(array, tmp, start, mid, end);
    }
}

int binary_search(vector<int> &array, int target) {
    int low = 0;
    int high = array.size() - 1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(array[mid] <= target){
            low = mid + 1;
        }else if(array[mid] > target){
            high = mid - 1;
        }
    }

    return low;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int qtd_shops;
    cin >> qtd_shops; 

    vector<int> prices(qtd_shops);
    for(int i = 0; i < qtd_shops; i++){
        cin >> prices[i];
    }

    vector<int> temp(qtd_shops);
    mergesort(prices, temp, 0, qtd_shops - 1);

    int plansToBuy;
    cin >> plansToBuy;

    int coins, result;
    for(int i = 0; i < plansToBuy; i++){
        cin >> coins;

        result = binary_search(prices, coins);
        cout << result << '\n';
    }
}