#include <bits/stdc++.h>

using namespace std;

long int maxSubarraySum(vector<int> &vetor){
    long long int sum = vetor[0]; // sum eh a soma de cada subvetor
    int atual; //atual eh o valor atual do laço
    long long int maxSum = sum; // maxSum eh a maior soma de todos os subvetores
     
    for(int i = 1; i < vetor.size(); i++){
        atual = vetor[i];

        if(atual > atual + sum){
            sum = atual; //se o valor atual eh maior, a soma do subvetor recomeça
        }else{
            sum = sum + atual;
        }

        if(sum > maxSum){
            maxSum = sum;
        }
    }

    return maxSum;
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
    int size;
    cin >> size;

    vector<int> values(size);
    for(int i = 0; i < size; i++){
        cin >> values[i];
    }

    cout << maxSubarraySum(values) << '\n';

    return 0;
}