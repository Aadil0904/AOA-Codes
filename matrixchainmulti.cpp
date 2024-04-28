#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int i, int j, vector<vector<int>>& brackets) {
    if (i == j)
        return 0;

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = MatrixChainOrder(p, i, k, brackets) + MatrixChainOrder(p, k + 1, j, brackets) 
                    + p[i - 1] * p[k] * p[j];
        if (cost < minCost) {
            minCost = cost;
            brackets[i][j] = k;
        }
    }
    return minCost;
}

void printBrackets(int i, int j, vector<vector<int>>& brackets) {
    if (i == j) {
        cout << char('A' + (i - 1));
        return;
    }

    cout << "(";
    printBrackets(i, brackets[i][j], brackets);
    cout << "";
    printBrackets(brackets[i][j] + 1, j, brackets);
    cout << ")";
}

int main() {
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> brackets(N, vector<int>(N, -1));

    cout << MatrixChainOrder(arr, 1, N - 1, brackets) << endl;

    cout << "Optimal Parenthesization is: ";
    printBrackets(1, N - 1, brackets);
    cout << endl;

    return 0;
}
