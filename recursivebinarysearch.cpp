#include <bits/stdc++.h>
using namespace std;

int recursivebinarysearch(vector<int> vec, int low, int high, int x) {

    while (high >= low) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == x) {
            return mid; 
        } else if (vec[mid] < x) {
            return recursivebinarysearch(vec,mid+1,high,x);
        } else {
            return recursivebinarysearch(vec,low,mid-1,x);
        }
    }
    return -1;
}


int main(){
    vector<int> vec = {9,8,32,6,23,78};
    sort(vec.begin(),vec.end());
    cout << recursivebinarysearch(vec,0,vec.size()-1,6);
}