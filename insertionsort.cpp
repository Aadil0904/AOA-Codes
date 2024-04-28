#include <bits/stdc++.h>
using namespace std;

vector<int> insertionsort(vector<int> arr){
    int n = arr.size();

    for (int i = 1; i < n; ++i){
        int k = arr[i];
        int j = i-1;

        while(k<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
    return arr;
}

int main(){
    vector<int> vec = {4,8,32,6,23,78};
    vector<int> newvec = insertionsort(vec);

    for (auto i : newvec){
        cout << i << endl;
    }
}