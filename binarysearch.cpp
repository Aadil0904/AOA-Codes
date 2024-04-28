#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> vec, int x) {
    int low = 0, high = vec.size() - 1, mid = 0;

    while (high >= low) {
        mid = low + (high - low) / 2;

        if (vec[mid] == x) {
            return mid; 
        } else if (vec[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int> vec = {9,8,32,6,23,78};
    sort(vec.begin(),vec.end());
    cout << binarysearch(vec,8);
}