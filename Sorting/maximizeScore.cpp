#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &array, int start, int mid, int end){
    vector<int> temp = array;

    int i1 = start;
    int i2 = mid + 1;

    for(int curr = start; curr <= end; curr++){
        if(i1 == (mid + 1)){ // left subarray is exhausted
            array[curr] = temp[i2++];
        } else if(i2 > end){ // right subarray is exhausted
            array[curr] = temp[i1++];
        } else if(temp[i1] <= temp[i2]){ // left element is smaller
            array[curr] = temp[i1++];
        } else{ // right element is smaller
            array[curr] = temp[i2++];
        }
    }
}

void mergesort(vector<int> &array, int start, int end){
    if(start < end) {
        int mid = (start + end) / 2;
        mergesort(array, start, mid);
        mergesort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases, halfWritten, score;
    cin >> testCases;
    
    while(testCases--){
        cin >> halfWritten;
        vector<int> array(2*halfWritten);

        for(int i = 0; i < 2*halfWritten; i++){
            cin >> array[i];
        }
        mergesort(array, 0, 2*halfWritten - 1);

        score = 0;
        for(int i = 0; i < 2*halfWritten; i+=2){
            score = score + array[i];
        }

        cout << score << endl;
    }

    return 0;
}
