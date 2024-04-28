#include <bits/stdc++.h>
using namespace std;

string lcs(string X, string Y, int m, int n, vector<vector<string>>& dp) {

    if (m == 0 || n == 0) return "";

    if (dp[m][n] != "") return dp[m][n];

    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = lcs(X, Y, m - 1, n - 1, dp) + X[m - 1];

    string lcs1 = lcs(X, Y, m, n - 1, dp);
    string lcs2 = lcs(X, Y, m - 1, n, dp);

    return dp[m][n] = (lcs1.size() > lcs2.size()) ? lcs1 : lcs2;
}

int main() {
    string X = "Aadil";
    string Y = "Aadil";

    int m = X.size();
    int n = Y.size();

    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
    
    cout << "LCS is " << lcs(X, Y, m, n, dp);
    cout << "Length of LCS is " << lcs(X, Y, m, n, dp).size() << endl;

    return 0;
}
