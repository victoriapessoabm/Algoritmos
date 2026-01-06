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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, difference;
    cin >> n >> difference;
    vector<int> array(n);

    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    vector<int> tmp(n);
    mergesort(array, tmp, 0, n - 1);

    int pointer1 = 0, pointer2 = 1, count = 0;
    while(pointer2 < n){
        int diff = array[pointer2] - array[pointer1];
        if(diff == difference){
            count++;
            pointer1++;
            pointer2++;
        } else if(diff > difference){
            pointer1++;
            if(pointer1 == pointer2){
                pointer2++;
            }
        } else{
            pointer2++;
        }
    }
    
    cout << count << "\n";

    return 0;
}
