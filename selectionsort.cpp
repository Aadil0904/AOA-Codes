#include <bits/stdc++.h>
using namespace std;

vector<int> selectionsort(vector<int> a){
    int n = a.size();
    int p;

    for(int i=0; i < n-1; ++i){
        p = i;
        for(int j = i+1; j < n; ++j){
            if (a[j] < a[p]){
                p = j;
            }
        }
        swap(a[i],a[p]);
    }
    return a;
}

int main(){
    vector<int> vec = {4,8,32,6,23,78};
    vector<int> newvec = selectionsort(vec);

    for (auto i : newvec){
        cout << i << endl;
    }
}