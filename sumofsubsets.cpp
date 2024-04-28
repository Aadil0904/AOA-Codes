#include <bits/stdc++.h>
using namespace std;

bool flag = 0;

void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int>& subset){
    if (targetSum == 0) {
        flag = 1;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++) cout << subset[i] << " ";
        cout << "]" << endl;
        return;
    }

    if (i == n) return;

    PrintSubsetSum(i + 1, n, set, targetSum, subset);

    if (set[i] <= targetSum) {
        subset.push_back(set[i]);
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);
        subset.pop_back();
    }
}

int main()
{
    int n, target;
    cin >> n >> target;
    int set[n];
    for(int i = 0; i < n; i++){
        cin >> set[i];
    }
    vector<int> subset;
    PrintSubsetSum(0, n, set, target, subset);
    cout << endl;
    if (!flag) {
        cout << "There is no such subset";
    }
    return 0;
}
