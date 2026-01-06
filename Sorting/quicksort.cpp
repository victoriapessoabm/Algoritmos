#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &array, int start, int end){
    int pivot = array[start];
    int i = start;
    int j = end + 1;

    do{
        do{
            i = i + 1;
        } while(i <= end && array[i] < pivot);

        do{
            j = j - 1;
        } while(j >= start && array[j] > pivot);

        swap(array[i], array[j]);

    } while(i < j);

    swap(array[i], array[j]);
    swap(array[start], array[j]);
    return j; // pivot index
}

void quicksort(vector<int> &array, int start, int end){
    if(start < end){
        int s;
        s = partition(array, start, end);
        quicksort(array, start, s - 1);
        quicksort(array, s + 1, end);
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
    quicksort(array, 0, n - 1);

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